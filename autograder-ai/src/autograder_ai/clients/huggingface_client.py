import os
from types import SimpleNamespace


class HuggingFaceLLMWrapper:
    """LangChain-compatible wrapper for a local HuggingFace model.

    Exposes an .invoke() method so it can be used anywhere the codebase
    expects a LangChain chat model (llm.invoke(messages) -> response.content).
    """

    def __init__(self, model, tokenizer, model_name: str = "", max_new_tokens: int = 500):
        self._model = model
        self._tokenizer = tokenizer
        self.model_name = model_name
        self._max_new_tokens = max_new_tokens

    def invoke(self, messages):
        import torch

        if isinstance(messages, list):
            prompt_text = (
                messages[-1].content
                if hasattr(messages[-1], "content")
                else str(messages[-1])
            )
        else:
            prompt_text = str(messages)

        formatted = self._tokenizer.apply_chat_template(
            [{"role": "user", "content": prompt_text}],
            tokenize=False,
            add_generation_prompt=True,
        )

        inputs = self._tokenizer(formatted, return_tensors="pt").to(self._model.device)

        with torch.no_grad():
            output_ids = self._model.generate(
                **inputs,
                max_new_tokens=self._max_new_tokens,
                do_sample=False,
                temperature=None,
                top_p=None,
                pad_token_id=self._tokenizer.eos_token_id,
            )

        new_tokens = output_ids[0][inputs["input_ids"].shape[1]:]
        text = self._tokenizer.decode(new_tokens, skip_special_tokens=True)

        return SimpleNamespace(content=text.strip())


class HuggingFaceClient:

    def __init__(self, model_name: str = None, quantization_bits: int = 8, max_new_tokens: int = 500, adapter_path: str = None) -> None:
        self.model_name = model_name or os.getenv("HF_MODEL_NAME", "meta-llama/Llama-3.2-3B-Instruct")
        self._quantization_bits = quantization_bits
        self._max_new_tokens = max_new_tokens
        self.adapter_path = adapter_path
        self._model = None
        self._tokenizer = None
        self.llm = None

    def _load_model(self):
        import torch
        from transformers import AutoTokenizer, AutoModelForCausalLM, BitsAndBytesConfig

        bits = self._quantization_bits
        suffix = f" + adapter from {self.adapter_path}" if self.adapter_path else ""
        print(f"[HuggingFaceClient] Loading {self.model_name} ({bits}-bit){suffix}...")
        if bits == 4:
            quantization_config = BitsAndBytesConfig(
                load_in_4bit=True,
                bnb_4bit_quant_type="nf4",
                bnb_4bit_compute_dtype=torch.bfloat16,
                bnb_4bit_use_double_quant=True,
            )
        else:
            quantization_config = BitsAndBytesConfig(load_in_8bit=True)
        tokenizer_source = self.adapter_path if self.adapter_path else self.model_name
        self._tokenizer = AutoTokenizer.from_pretrained(tokenizer_source)
        self._model = AutoModelForCausalLM.from_pretrained(
            self.model_name,
            device_map="auto",
            quantization_config=quantization_config,
        )
        if self.adapter_path:
            from peft import PeftModel
            self._model = PeftModel.from_pretrained(self._model, self.adapter_path)
        self.llm = HuggingFaceLLMWrapper(
            self._model, self._tokenizer,
            model_name=self.model_name,
            max_new_tokens=self._max_new_tokens,
        )
        print("[HuggingFaceClient] Model ready.")

    def get_llm(self) -> HuggingFaceLLMWrapper:
        if self.llm is None:
            self._load_model()
        return self.llm
