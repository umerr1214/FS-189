"""
finetune_qwen.py

QLoRA fine-tuning of Qwen2.5-Coder-7B-Instruct on the EvalBright test-generation
dataset.  Reads train.jsonl / val.jsonl produced by dataset/prepare_dataset.py and
saves a LoRA adapter to ./fine_tuned_adapter/.

Requirements (in addition to existing pyproject.toml deps):
    peft>=0.9.0, trl>=0.12.0, datasets>=3.0.0

Run from autograder-ai/:
    python finetune_qwen.py
"""

import os
import json
import torch

from pathlib import Path
from datasets import load_dataset
from transformers import (
    AutoModelForCausalLM,
    AutoTokenizer,
    BitsAndBytesConfig,
    TrainingArguments,
)
from peft import LoraConfig, get_peft_model, TaskType
from trl import SFTTrainer

# ── Config (edit these before running) ─────────────────────────────────────────
MODEL_NAME       = "Qwen/Qwen2.5-Coder-7B-Instruct"
TRAIN_DATA       = "../dataset/train.jsonl"
VAL_DATA         = "../dataset/val.jsonl"
OUTPUT_DIR       = "./fine_tuned_adapter"

# LoRA
LORA_R           = 16
LORA_ALPHA       = 32
LORA_DROPOUT     = 0.05
TARGET_MODULES   = [
    "q_proj", "k_proj", "v_proj", "o_proj",
    "gate_proj", "up_proj", "down_proj",
]

# Training
NUM_EPOCHS       = 3
LEARNING_RATE    = 2e-4
BATCH_SIZE       = 2       # per device; increase if VRAM allows
GRAD_ACCUM       = 8       # effective batch = BATCH_SIZE * GRAD_ACCUM = 16
MAX_SEQ_LENGTH   = 2048
WARMUP_RATIO     = 0.03
LOGGING_STEPS    = 10
# ───────────────────────────────────────────────────────────────────────────────


def print_trainable_params(model) -> None:
    trainable, total = 0, 0
    for _, p in model.named_parameters():
        total += p.numel()
        if p.requires_grad:
            trainable += p.numel()
    pct = 100 * trainable / total if total else 0
    print(f"\nTrainable params : {trainable:,}  /  {total:,}  ({pct:.2f}%)")
    print(f"(Only the LoRA adapter is being trained — base model is frozen)\n")


# ── Step 1: Load dataset ───────────────────────────────────────────────────────
print("=" * 60)
print("Step 1 — Loading dataset")
print("=" * 60)

data_files = {"train": TRAIN_DATA, "validation": VAL_DATA}
raw_datasets = load_dataset("json", data_files=data_files)

print(f"  Train examples      : {len(raw_datasets['train'])}")
print(f"  Validation examples : {len(raw_datasets['validation'])}")


# ── Step 2: Load tokenizer ────────────────────────────────────────────────────
print("\n" + "=" * 60)
print("Step 2 — Loading tokenizer")
print("=" * 60)

tokenizer = AutoTokenizer.from_pretrained(MODEL_NAME, trust_remote_code=True)
tokenizer.pad_token = tokenizer.eos_token   # Qwen uses eos as pad
tokenizer.padding_side = "right"            # pad on right for causal LM


# ── Step 3: Format dataset with chat template ─────────────────────────────────
print("\n" + "=" * 60)
print("Step 3 — Applying Qwen chat template")
print("=" * 60)

def format_example(example):
    """Convert messages list → single string using Qwen's chat template."""
    text = tokenizer.apply_chat_template(
        example["messages"],
        tokenize=False,
        add_generation_prompt=False,
    )
    return {"text": text}

train_ds = raw_datasets["train"].map(format_example, desc="Formatting train")
val_ds   = raw_datasets["validation"].map(format_example, desc="Formatting val")

# Sanity check — print one formatted example
print("\nSample formatted example (first 400 chars):")
print(train_ds[0]["text"][:400])
print("...")


# ── Step 4: Load model in 4-bit (QLoRA) ───────────────────────────────────────
print("\n" + "=" * 60)
print("Step 4 — Loading Qwen2.5-Coder-7B-Instruct in 4-bit (QLoRA)")
print("=" * 60)

bnb_config = BitsAndBytesConfig(
    load_in_4bit=True,
    bnb_4bit_quant_type="nf4",
    bnb_4bit_compute_dtype=torch.float16,
    bnb_4bit_use_double_quant=True,
)

model = AutoModelForCausalLM.from_pretrained(
    MODEL_NAME,
    quantization_config=bnb_config,
    device_map="auto",
    trust_remote_code=True,
)
model.config.use_cache = False              # required for gradient checkpointing
model.config.pretraining_tp = 1            # avoids tensor-parallel warnings


# ── Step 5: Apply LoRA ────────────────────────────────────────────────────────
print("\n" + "=" * 60)
print("Step 5 — Applying LoRA adapter")
print("=" * 60)

lora_config = LoraConfig(
    r=LORA_R,
    lora_alpha=LORA_ALPHA,
    target_modules=TARGET_MODULES,
    lora_dropout=LORA_DROPOUT,
    bias="none",
    task_type=TaskType.CAUSAL_LM,
)

model = get_peft_model(model, lora_config)
print_trainable_params(model)


# ── Step 6: Training arguments ────────────────────────────────────────────────
training_args = TrainingArguments(
    output_dir=OUTPUT_DIR,
    num_train_epochs=NUM_EPOCHS,
    per_device_train_batch_size=BATCH_SIZE,
    gradient_accumulation_steps=GRAD_ACCUM,
    learning_rate=LEARNING_RATE,
    warmup_ratio=WARMUP_RATIO,
    eval_strategy="epoch",
    save_strategy="epoch",
    load_best_model_at_end=True,
    metric_for_best_model="eval_loss",
    greater_is_better=False,
    fp16=True,
    logging_steps=LOGGING_STEPS,
    report_to="none",           # disable wandb / tensorboard
    gradient_checkpointing=True,
    dataloader_num_workers=0,   # avoid multiprocessing issues on Windows
)


# ── Step 7: Train ─────────────────────────────────────────────────────────────
print("\n" + "=" * 60)
print("Step 6 — Training")
print(f"  Epochs          : {NUM_EPOCHS}")
print(f"  Effective batch : {BATCH_SIZE * GRAD_ACCUM}")
print(f"  LR              : {LEARNING_RATE}")
print(f"  Max seq length  : {MAX_SEQ_LENGTH}")
print("=" * 60 + "\n")

trainer = SFTTrainer(
    model=model,
    tokenizer=tokenizer,
    train_dataset=train_ds,
    eval_dataset=val_ds,
    dataset_text_field="text",
    max_seq_length=MAX_SEQ_LENGTH,
    args=training_args,
)

trainer.train()


# ── Step 8: Save adapter ──────────────────────────────────────────────────────
print("\n" + "=" * 60)
print("Step 7 — Saving LoRA adapter")
print("=" * 60)

trainer.model.save_pretrained(OUTPUT_DIR)
tokenizer.save_pretrained(OUTPUT_DIR)

adapter_files = list(Path(OUTPUT_DIR).rglob("adapter_model*"))
print(f"  Adapter saved to : {OUTPUT_DIR}")
print(f"  Adapter files    : {[f.name for f in adapter_files]}")


# ── Step 9: Quick test inference ──────────────────────────────────────────────
print("\n" + "=" * 60)
print("Step 8 — Test inference on one validation example")
print("=" * 60)

model.eval()

sample = val_ds[0]
# Rebuild the prompt without the assistant turn
sample_messages = raw_datasets["validation"][0]["messages"][:2]  # system + user only
prompt = tokenizer.apply_chat_template(
    sample_messages,
    tokenize=False,
    add_generation_prompt=True,
)
inputs = tokenizer(prompt, return_tensors="pt").to(model.device)

with torch.no_grad():
    output_ids = model.generate(
        **inputs,
        max_new_tokens=512,
        do_sample=False,
        pad_token_id=tokenizer.eos_token_id,
    )

# Decode only the newly generated tokens
generated = tokenizer.decode(
    output_ids[0][inputs["input_ids"].shape[1]:],
    skip_special_tokens=True,
)

print("\nPrompt (user turn):")
print(sample_messages[1]["content"][:300])
print("\nModel output:")
print(generated)

# Validate JSON
try:
    parsed = json.loads(generated.strip())
    print(f"\n✓ Output is valid JSON  ({len(parsed)} test cases)")
except json.JSONDecodeError as e:
    print(f"\n✗ Output is NOT valid JSON: {e}")
    print("  (This is normal for the first fine-tune with a small dataset)")

print("\nFine-tuning complete.")
print(f"Load the adapter later with:")
print(f"  from peft import PeftModel")
print(f"  model = PeftModel.from_pretrained(base_model, '{OUTPUT_DIR}')")
