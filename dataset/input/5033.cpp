#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Function to replace characters in-place (Logical Error: replaces only the first occurrence)
void replaceChar(std::string& s, char oldChar, char newChar) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == oldChar) {
            s[i] = newChar;
            // Logical error: The function breaks after replacing the first occurrence.
            // It should continue to replace all occurrences.
            break;
        }
    }
}

int main() {
    std::vector<std::pair<std::string, std::string>> test_cases = {
        {"hello world,o,x", "hellx wxrld"}, // Expected: hellx wxrld, Actual: hellx world (FAIL)
        {"apple,p,b", "abble"},             // Expected: abble, Actual: abple (FAIL)
        {"banana,z,q", "banana"},           // Expected: banana, Actual: banana (PASS) - no 'z'
        {",a,b", ""},                       // Expected: "", Actual: "" (PASS) - empty string
        {"aaaaa,a,b", "bbbbb"}              // Expected: bbbbb, Actual: baaaa (FAIL)
    };

    for (const auto& tc : test_cases) {
        std::string input_str = tc.first;
        std::string expected_output = tc.second;

        std::stringstream ss(input_str);
        std::string s_val_str;
        std::string old_char_str;
        std::string new_char_str;

        std::getline(ss, s_val_str, ',');
        std::getline(ss, old_char_str, ',');
        std::getline(ss, new_char_str);

        std::string original_s = s_val_str;
        char oldC = old_char_str.empty() ? '\0' : old_char_str[0];
        char newC = new_char_str.empty() ? '\0' : new_char_str[0];

        replaceChar(original_s, oldC, newC);

        std::cout << "Input: \"" << s_val_str << "\", oldChar: '" << oldC << "', newChar: '" << newC << "'" << std::endl;
        std::cout << "Expected: \"" << expected_output << "\"" << std::endl;
        std::cout << "Actual: \"" << original_s << "\"" << std::endl;
        std::cout << (original_s == expected_output ? "PASS" : "FAIL") << std::endl << std::endl;
    }

    return 0;
}