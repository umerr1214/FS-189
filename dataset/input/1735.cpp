#include <iostream>
#include <string>
#include <cctype> // For isprint, though not directly used in the final version of the robustness issue

class Printer {
public:
    void print(int num) {
        std::cout << "Integer: " << num << std::endl;
    }

    void print(const std::string& text) {
        std::cout << "String: " << text << std::endl;
    }

    // Robustness issue: For non-printable ASCII characters (like control characters),
    // it prints their integer ASCII value instead of the character itself.
    // While this prevents potential terminal display issues, it deviates from
    // the intuitive expectation of "displaying the character" for all valid char inputs,
    // making it less robust in terms of consistent user experience for char printing.
    void print(char character) {
        // Check if character is within printable ASCII range (32 to 126)
        if (character >= 32 && character <= 126) {
            std::cout << "Character: " << character << std::endl;
        } else {
            // For control characters or other non-printable ASCII, print its integer value.
            // This is a "robustness issue" because the user might expect the actual
            // character to be displayed or a more explicit handling (e.g., "[Non-printable]")
            // rather than its raw ASCII value, leading to unexpected output for some inputs.
            std::cout << "Character (ASCII value): " << static_cast<int>(character) << std::endl;
        }
    }
};

int main() {
    Printer p;
    p.print(123);
    p.print("Hello, C++!");
    p.print('A');
    p.print('$');
    p.print('\n'); // Newline character - will print its ASCII value (10)
    p.print('\t'); // Tab character - will print its ASCII value (9)
    p.print(static_cast<char>(27)); // ESC character - will print its ASCII value (27)
    p.print(static_cast<char>(127)); // DEL character - will print its ASCII value (127)
    return 0;
}