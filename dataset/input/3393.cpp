#include <iostream>
#include <cstring> // For strlen
#include <string>  // For std::string in main

// Correct and efficient implementation
char* reverse_cstring(char* str) {
    if (str == nullptr) {
        return nullptr; // Handle NULL input gracefully
    }

    size_t length = strlen(str); // Calculate length once
    if (length <= 1) {
        return str; // Empty or single-character strings are already reversed
    }

    char* start = str;
    char* end = str + length - 1; // Pointer to the last character

    while (start < end) {
        // Swap characters
        char temp = *start;
        *start = *end;
        *end = temp;

        // Move pointers towards the center
        start++;
        end--;
    }
    return str; // Return pointer to the modified string
}

int main() {
    // Test cases
    std::string test_inputs[] = {
        "",
        "a",
        "ab",
        "abc",
        "hello",
        "racecar",
        "long_string_to_test_correctness_and_efficiency_with_many_characters_and_words_and_symbols_like_!@#$%",
        "__NULL__" // Special indicator for NULL input
    };
    std::string expected_outputs[] = {
        "",
        "a",
        "ba",
        "cba",
        "olleh",
        "racecar",
        "%#$@!_slobmys_dna_sdrow_dna_sretcarahc_ynam_htiw_ycneiciffe_dna_ssenctcerroc_tset_ot_gnirts_gnol",
        "__NULL__" // Expected for NULL input (returns NULL)
    };

    for (size_t i = 0; i < sizeof(test_inputs) / sizeof(test_inputs[0]); ++i) {
        std::cout << "Test Case " << i + 1 << ":\n";
        std::cout << "Input: \"" << test_inputs[i] << "\"\n";

        char* input_cstr = nullptr;
        char buffer[200]; // Buffer to hold mutable strings

        if (test_inputs[i] == "__NULL__") {
            input_cstr = nullptr;
            std::cout << "Expected: " << expected_outputs[i] << "\n";
            char* result = reverse_cstring(input_cstr); // Call with NULL, should return NULL
            std::cout << "Result: " << (result == nullptr ? "NULL" : result) << "\n";
            if (result == nullptr && expected_outputs[i] == "__NULL__") {
                std::cout << "Status: PASSED\n";
            } else {
                std::cout << "Status: FAILED\n";
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

    return 0;
}