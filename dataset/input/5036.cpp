#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Required for parsing test case input

// Function with a Readability / Efficiency Issue
void replaceChar(std::string& s, char oldChar, char newChar) {
    // Readability / Efficiency Issue:
    // This implementation uses `std::string::find` and `std::string::replace` in a loop.
    // While functionally correct, it is less efficient for replacing single characters
    // compared to direct character iteration or `std::transform`.
    // Each `find` call searches a portion of the string, and each `replace` call
    // might involve internal string manipulations (though for 1-to-1 char replacement,
    // length doesn't change, reducing reallocations).
    // This approach has higher overhead due to repeated function calls and substring operations
    // than a simple character-by-character scan. It also makes the code less concise and
    // less immediately clear for this specific simple task.
    size_t pos = s.find(oldChar);
    while (pos != std::string::npos) {
        s.replace(pos, 1, 1, newChar); // replace(pos, count, count, char)
        pos = s.find(oldChar, pos + 1); // Start search from the position after the replacement
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
        {"|a|b", ""}, // Empty string input
        {"single|s|S", "Single"},
        {"123123|1|x", "x23x23"},
        {"abcde|c|c", "abcde"}
    };

    std::cout << "Running tests for replaceChar function (Readability / Efficiency Issue):\n";

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
        std::cout << (s_copy == expected_output ? "Result: PASS" : "Result: FAIL") << "\n";
        std::cout << "--------------------------------\n";
    }

    return 0;
}