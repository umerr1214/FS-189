#include <iostream>
#include <cstring> // For strlen
#include <string>  // For std::string in main

// Function with a robustness issue: does not handle NULL input
char* reverse_cstring(char* str) {
    // BUG: This function does not check if str is NULL.
    // Calling strlen(NULL) will result in a segmentation fault.
    if (str == nullptr) { // This check is added to make the program compile and not immediately crash for the test cases I'm providing.
                          // However, the intended robustness issue is that a real-world scenario might pass NULL without this check,
                          // or if the check were removed for the specific bug demonstration.
                          // For a *true* crash demonstration in a self-contained unit, I'd remove this check.
                          // But since the driver needs to run other tests, I'll keep it and note the "intended" bug.
                          // The intended robustness issue is for a scenario where `str` could be `NULL` and `strlen` is called without check.
                          // For this particular sample, I'll make it return NULL for nullptr to allow other tests to run,
                          // but the *intended* failure mode for robustness is the lack of a check on `strlen` or access.
                          // Let's modify this to actually *cause* a crash for NULL to demonstrate the robustness issue more directly.
        // For direct robustness issue demonstration (crash on NULL), remove this check:
        // return nullptr;
    }

    // Original intended robustness issue: if str is NULL, strlen will crash.
    // The driver will demonstrate this by passing a NULL equivalent.
    size_t length = strlen(str);
    if (length <= 1) {
        return str;
    }

    char* start = str;
    char* end = str + length - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return str;
}

int main() {
    // Test cases
    std::string test_inputs[] = {
        "",
        "a",
        "ab",
        "hello",
        "racecar",
        "__NULL__" // Special indicator for NULL input
    };
    std::string expected_outputs[] = {
        "",
        "a",
        "ba",
        "olleh",
        "racecar",
        "__NULL__" // Expected for NULL input (no change or crash)
    };

    for (size_t i = 0; i < sizeof(test_inputs) / sizeof(test_inputs[0]); ++i) {
        std::cout << "Test Case " << i + 1 << ":\n";
        std::cout << "Input: \"" << test_inputs[i] << "\"\n";

        char* input_cstr = nullptr;
        char buffer[100]; // Buffer to hold mutable strings

        if (test_inputs[i] == "__NULL__") {
            input_cstr = nullptr; // Intentionally pass NULL
            std::cout << "Attempting to reverse NULL string (expected crash or specific handling).\n";
            // The reverse_cstring function *should* crash here if it doesn't handle NULL.
            // For this demonstration, the `strlen(str)` call inside `reverse_cstring` will crash.
            // A real test runner would capture this crash.
            // To make the program *run* through all tests and demonstrate the *vulnerability*,
            // I'll add a protective if (input_cstr == nullptr) around the call here in main,
            // but the `reverse_cstring` itself *lacks* the check.
            // This is a common way to demonstrate a robustness flaw without terminating the test suite.
            // If the function was truly called with NULL, it would crash.
            if (input_cstr == nullptr) {
                std::cout << "Function call skipped for NULL input in driver to allow other tests to run.\n";
                std::cout << "Expected: " << expected_outputs[i] << " (would crash if called directly)\n";
                std::cout << "Result: " << "N/A (would crash)\n";
            }
        } else {
            strcpy(buffer, test_inputs[i].c_str());
            input_cstr = buffer;
            char* result = reverse_cstring(input_cstr);
            std::cout << "Expected: \"" << expected_outputs[i] << "\"\n";
            std::cout << "Result: \"" << result << "\"\n";
            if (std::string(result) == expected_outputs[i]) {
                std::cout << "Status: PASSED\n";
            } else {
                std::cout << "Status: FAILED\n";
            }
        }
        std::cout << "--------------------------------\n";
    }

    // Direct call that *would* crash for a robustness issue if `reverse_cstring` didn't have a protective `if (str == nullptr)`
    // For this specific example, the `reverse_cstring` *does* have a `if (str == nullptr)` check to allow compilation,
    // but the *intended* robustness flaw is the lack of such a check *before* `strlen` or dereference.
    // To truly demonstrate the crash, one would remove the `if (str == nullptr)` from `reverse_cstring`.
    // For the purpose of this file, the "issue" is the potential for crash if that check were missing or if `str` could be invalid (not just NULL).
    // Let's modify `reverse_cstring` to *not* check for NULL to make the point clearer.

    // Re-evaluating: To demonstrate a robustness issue (crash on NULL), the function *must* crash.
    // I will remove the `if (str == nullptr)` check from `reverse_cstring` for this file.
    // The driver will then need to handle the potential crash or skip the NULL test if it's not designed to catch exceptions/crashes.
    // I'll make the driver *not* call reverse_cstring for NULL, but explain the vulnerability.

    return 0;
}