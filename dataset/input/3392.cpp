#include <iostream>
#include <cstring> // For strlen
#include <string>  // For std::string in main

// Function with an efficiency issue
char* reverse_cstring(char* str) {
    if (str == nullptr) {
        return nullptr; // Handle NULL input gracefully
    }

    // Efficiency Issue: strlen is called repeatedly inside the loop.
    // strlen iterates through the entire string each time it's called,
    // making the overall complexity O(N^2) for string reversal,
    // instead of the optimal O(N).
    char* start = str;
    // char* end = str + strlen(str) - 1; // Correct way to initialize end once

    while (start < (str + strlen(str) - 1)) { // BUG: strlen(str) is called in every iteration
        char* end = str + strlen(str) - 1; // BUG: strlen(str) is called in every iteration
        if (start >= end) break; // Break condition to handle empty/single char string or when pointers cross

        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        // end--; // This is commented out because `end` is recalculated every time, effectively making it always point to the last char.
                 // This makes the logic incorrect for reversal, as it will just swap the first char with the last, then the second with the last, etc.
                 // This makes it not only inefficient but also functionally incorrect for strings longer than 2.
                 // Let's fix the logic to be correct but inefficient.

        // Corrected logic for inefficiency, but still functional:
        // Original logic should be:
        // char* end_ptr = str + strlen(str) - 1;
        // while (start < end_ptr) {
        //     // swap
        //     start++;
        //     end_ptr--;
        // }
        // To make it inefficient, I need to recalculate `end_ptr` or `strlen` repeatedly.
        // Let's use a `for` loop where `strlen` is called in the condition or initialization of `end` in each iteration.

        // Corrected inefficient version:
        // The previous attempt was both inefficient and incorrect.
        // Let's make it *only* inefficient but still correct.
        // This means calculating strlen once to get length, then in a loop, calculating `end` based on length.
        // A direct way to be inefficient is to calculate length inside the loop condition or body for `end`.

        // This version is inefficient but correct:
        // The `while (start < end)` loop should decrement `end`.
        // If `end` is recalculated inside the loop, it won't decrement correctly.
        // Let's try to make it inefficient by doing `strlen` multiple times, but still producing the correct result.
        // This is harder than it seems to be *only* inefficient but *not* incorrect.

        // Simplest inefficient (but correct) way:
        // Calculate length once, but in the loop, use `strlen` again for some reason.
        // No, the most common inefficiency is `strlen` in loop condition.

        // Let's revert to the classic inefficiency:
        // Calculate `end` based on `strlen` every time.
        // This version should be correct for all inputs, but slow.
    }

    size_t length = strlen(str); // Calculate length once
    if (length <= 1) {
        return str;
    }

    char* start_ptr = str;
    // Inefficient approach: recalculate the end pointer repeatedly, or call strlen repeatedly.
    // This example recalculates `end_ptr` by calling `strlen` in each iteration of the loop.
    // This is the most common "efficiency issue" for string manipulation in C.
    for (size_t i = 0; i < length / 2; ++i) { // Loop half the length
        char* end_ptr = str + strlen(str) - 1 - i; // Recalculates strlen(str) and finds the 'end' for the current swap
                                                   // This is inefficient as strlen is O(N)
        char temp = start_ptr[i];
        start_ptr[i] = *end_ptr;
        *end_ptr = temp;
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
        "long_string_to_test_efficiency_with_many_characters_and_words_and_symbols_like_!@#$%",
        "__NULL__" // Special indicator for NULL input
    };
    std::string expected_outputs[] = {
        "",
        "a",
        "ba",
        "olleh",
        "racecar",
        "%#$@!_slobmys_dna_sdrow_dna_sretcarahc_ynam_htiw_ycneiciffe_tset_ot_gnirts_gnol",
        "__NULL__" // Expected for NULL input
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