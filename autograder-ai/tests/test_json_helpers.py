import unittest
from types import SimpleNamespace

from autograder_ai.utils import extract_json
from autograder_ai.workflows.nodes.test_generation import (
    generate_test_cases_node,
    _salvage_test_case_objects,
)


class FakeLLM:
    def __init__(self, responses):
        self.responses = list(responses)
        self.prompts = []

    def invoke(self, prompt):
        self.prompts.append(prompt)
        return SimpleNamespace(content=self.responses.pop(0))


class ExtractJsonTests(unittest.TestCase):
    def test_extracts_closed_fenced_json(self):
        content = '```json\n[{"input":{"n":2},"expected_output":true}]\n```'

        self.assertEqual(
            extract_json(content),
            '[{"input":{"n":2},"expected_output":true}]',
        )

    def test_extracts_unclosed_fenced_json_when_array_is_complete(self):
        content = '```json\n[{"input":{"n":2},"expected_output":true}]'

        self.assertEqual(
            extract_json(content),
            '[{"input":{"n":2},"expected_output":true}]',
        )

    def test_extracts_nested_json_with_surrounding_text(self):
        content = (
            'Here are the cases:\n'
            '[{"input":{"values":[1,2,3]},"expected_output":"[ok]"}]\n'
            'Done.'
        )

        self.assertEqual(
            extract_json(content),
            '[{"input":{"values":[1,2,3]},"expected_output":"[ok]"}]',
        )

    def test_skips_non_json_bracketed_text(self):
        content = (
            'Here is [not json], followed by the real payload:\n'
            '[{"input":{"n":4},"expected_output":false}]'
        )

        self.assertEqual(
            extract_json(content),
            '[{"input":{"n":4},"expected_output":false}]',
        )

    def test_rejects_incomplete_json(self):
        content = '```json\n[{"input":{"n":2},"expected_output":true}'

        with self.assertRaises(ValueError):
            extract_json(content)


class GenerateTestCasesNodeTests(unittest.TestCase):
    def test_salvages_complete_objects_from_truncated_array(self):
        content = (
            '```json\n['
            '{"input":{"n":0},"expected_output":1,"description":"zero"},'
            '{"input":{"n":5},"expected_output":120,"description":"five"},'
            '{"input":{"n":999},"expected_output":'
        )

        self.assertEqual(
            _salvage_test_case_objects(content),
            [
                {"input": {"n": 0}, "expected_output": 1, "description": "zero"},
                {"input": {"n": 5}, "expected_output": 120, "description": "five"},
            ],
        )

    def test_repairs_invalid_initial_json(self):
        llm = FakeLLM([
            '```json\n[{"input":{"n":2},"expected_output":',
            '[{"input":{"n":2},"expected_output":true,"description":"prime"}]',
        ])
        node = generate_test_cases_node(llm)

        state = {
            "question_id": "q_1",
            "question": "Write is_prime(n).",
            "code": "def is_prime(n): return n == 2",
            "test_cases": [],
        }

        result = node(state)

        self.assertEqual(len(llm.prompts), 2)
        self.assertEqual(
            result["test_cases"],
            [{"input": {"n": 2}, "expected_output": True, "description": "prime"}],
        )

    def test_accepts_wrapped_test_cases_array(self):
        llm = FakeLLM([
            '{"test_cases":[{"input":{"n":2},"expected_output":true,"description":"prime"}]}',
        ])
        node = generate_test_cases_node(llm)

        state = {
            "question_id": "q_1",
            "question": "Write is_prime(n).",
            "code": "def is_prime(n): return n == 2",
            "test_cases": [],
        }

        result = node(state)

        self.assertEqual(len(llm.prompts), 1)
        self.assertEqual(
            result["test_cases"],
            [{"input": {"n": 2}, "expected_output": True, "description": "prime"}],
        )


if __name__ == "__main__":
    unittest.main()
