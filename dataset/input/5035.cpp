#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Required for parsing test case input

// Function with a Robustness Issue: Out-of-bounds access
void replaceChar(std::string& s, char oldChar, char newChar) {
    // Robustness Issue: The loop condition `i <= s.length()` is incorrect.
    // It causes an out-of-bounds access when `i` equals `s.length()`,
    // as valid indices for a string of length L are 0 to L-1.
    // Accessing s[s.length()] leads to undefined behavior, which can include crashes,
    // memory corruption, or unexpected results, especially for empty strings or specific inputs.
    for (size_t i = 0; i <= s.length(); ++i) { // BUG: Should be i < s.length()
        if (s[i] == oldChar) {
            s[i] = newChar;
        }
    }
}

int main() {
    // This code simulates the execution environment where test cases are provided.
    // It parses an encoded string to extract the arguments for replaceChar.
    std::vector<std::pair<std::string, std::string>> test_cases_data = {
        {"hello world|o|x", "hellx wxrld"},
        {"programming|g|G", "proGramminG"},
        {"aaaaa|a|b", "bbbbb"},
        {"nochange|z|q", "nochange"},
        {"|a|b", ""}, // Empty string input - likely to cause a crash here
        {"single|s|S", "Single"},
        {"123123|1|x", "x23x23"},
        {"abcde|c|c", "abcde"}
    };

    std::cout << "Running tests for replaceChar function (Robustness Issue):\n";

    for (const auto& tc : test_cases_data) {
        std::string input_str_encoded = tc.first;
        std::string expected_output = tc.second;

        // Parse the encoded input string "s_val|oldC_val|newC_val"
        std::string s_val_str;
        std::string old_char_str;
        std::string new_char_str;
        std::istringstream iss(input_str_encoded);
        
        std::getline(iss, s_val_str, '|');
        std::getline(iss, old_char_str, '|');
        std::getline(iss, new_char_str);

        std::string s_to_modify = s_val_str;
        char actual_old_char = old_char_str.empty() ? '\0' : old_char_str[0];
        char actual_new_char = new_char_str.empty() ? '\0' : new_char_str[0];

        std::string s_copy = s_to_modify; // Make a copy to pass by reference

        std::cout << "Input: \"" << s_to_modify << "\", oldChar: '" << actual_old_char << "', newChar: '" << actual_new_char << "'\n";
        replaceChar(s_copy, actual_old_char, actual_new_char);
        std::cout << "Output: \"" << s_copy << "\", Expected: \"" << expected_output << "\"\n";
        // Note: For robustness issues, the comparison might be misleading if the program crashes or produces garbage.
        std::cout << (s_copy == expected_output ? "Result: PASS" : "Result: FAIL (or crash likely for some inputs)") << "\n";
        std::cout << "--------------------------------\n";
    }

    return 0;
}