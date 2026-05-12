import json
import re


def sanitize_json(text: str) -> str:
    # Replace Python None with JSON null
    text = re.sub(r'\bNone\b', 'null', text)
    # Replace Python True with JSON true
    text = re.sub(r'\bTrue\b', 'true', text)
    # Replace Python False with JSON false
    text = re.sub(r'\bFalse\b', 'false', text)
    # Remove trailing commas before closing brackets/braces
    text = re.sub(r',(\s*[}\]])', r'\1', text)
    return text


def extract_json(text: str) -> str:
    """Extract the first complete JSON array/object from an LLM response.

    Local chat models often wrap JSON in markdown fences, and sometimes omit the
    closing fence. This function strips those wrappers and then finds a balanced
    JSON value while respecting strings and escaped characters.
    """
    stripped = _strip_code_fence(text)
    last_error: Exception | None = None

    for start, char in enumerate(stripped):
        if char not in "[{":
            continue

        try:
            json_value = sanitize_json(_extract_balanced_json(stripped, start))
            json.loads(json_value)
            return json_value
        except (json.JSONDecodeError, ValueError) as error:
            if str(error).startswith("Incomplete JSON"):
                raise ValueError(f"No valid complete JSON value found: {error}") from error
            last_error = error

    if last_error is not None:
        raise ValueError(f"No valid complete JSON value found: {last_error}")

    raise ValueError("No JSON array or object found in LLM response")


def _strip_code_fence(text: str) -> str:
    stripped = text.strip()
    stripped = re.sub(r'^```(?:json)?\s*', '', stripped, flags=re.IGNORECASE)
    stripped = re.sub(r'\s*```$', '', stripped)
    return stripped.strip()


def _extract_balanced_json(text: str, start: int) -> str:
    opening = text[start]
    if opening not in "[{":
        raise ValueError("JSON must start with '[' or '{'")

    matching = {"]": "[", "}": "{"}
    stack = [opening]
    in_string = False
    escaped = False

    for index in range(start + 1, len(text)):
        char = text[index]

        if escaped:
            escaped = False
            continue

        if char == "\\" and in_string:
            escaped = True
            continue

        if char == '"':
            in_string = not in_string
            continue

        if in_string:
            continue

        if char in "[{":
            stack.append(char)
        elif char in "]}":
            if not stack or stack[-1] != matching[char]:
                raise ValueError(f"Mismatched JSON delimiter at character {index}")
            stack.pop()

            if not stack:
                return text[start:index + 1]

    raise ValueError("Incomplete JSON array or object in LLM response")
