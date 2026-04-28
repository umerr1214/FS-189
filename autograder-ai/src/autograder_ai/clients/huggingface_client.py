import os
from types import SimpleNamespace


class HuggingFaceLLMWrapper:
    """LangChain-compatible wrapper for a local HuggingFace model.

    Exposes an .invoke() method so it can be used anywhere the codebase
    expects a LangChain chat model (llm.invoke(messages) -> response.content).
    """

    def __init__(self, model, tokenizer):
        self._model = model
        self._tokenizer = tokenizer

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
                max_new_tokens=500,
                do_sample=False,
                temperature=None,
                top_p=None,
                pad_token_id=self._tokenizer.eos_token_id,
            )

        new_tokens = output_ids[0][inputs["input_ids"].shape[1]:]
        text = self._tokenizer.decode(new_tokens, skip_special_tokens=True)

        return SimpleNamespace(content=text.strip())


class HuggingFaceClient:

    def __init__(self) -> None:
        self.model_name = os.getenv("HF_MODEL_NAME", "meta-llama/Llama-3.2-3B-Instruct")
        self._model = None
        self._tokenizer = None
        self.llm = None

    def _load_model(self):
        from transformers import AutoTokenizer, AutoModelForCausalLM, BitsAndBytesConfig

        print(f"[HuggingFaceClient] Loading {self.model_name} (8-bit quantized)...")
        quantization_config = BitsAndBytesConfig(load_in_8bit=True)
        self._tokenizer = AutoTokenizer.from_pretrained(self.model_name)
        self._model = AutoModelForCausalLM.from_pretrained(
            self.model_name,
            device_map="auto",
            quantization_config=quantization_config,
        )
        self.llm = HuggingFaceLLMWrapper(self._model, self._tokenizer)
        print("[HuggingFaceClient] Model ready.")

    def get_llm(self) -> HuggingFaceLLMWrapper:
        if self.llm is None:
            self._load_model()
        return self.llm
