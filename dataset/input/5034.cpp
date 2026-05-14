#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Function to replace characters in-place (Semantic Error: inefficient use of erase/insert)
void replaceChar(std::string& s, char oldChar, char newChar) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == oldChar) {
            // Semantic error: Instead of direct character assignment (s[i] = newChar;),
            // the code uses `erase` followed by `insert`.
            // While this produces the correct result for single character replacement,
            // it is highly inefficient as `erase` and `insert` operations on std::string
            // can involve shifting subsequent characters in memory, leading to O(N) complexity
            // for each replacement, resulting in O(N*M) overall complexity (M = number of replacements)
            // instead of the optimal O(N) for direct assignment.
            s.erase(i, 1);
            s.insert(i, 1, newChar);
        }
    }
}

int main() {
    std::vector<std::pair<std::string, std::string>> test_cases = {
        {"hello world,o,x", "hellx wxrld"},
        {"apple,p,b", "abble"},
        {"banana,z,q", "banana"},
        {",a,b", ""},
        {"aaaaa,a,b", "bbbbb"}
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