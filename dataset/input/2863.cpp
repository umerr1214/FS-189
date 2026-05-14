#include <iostream>
#include <string>
#include <vector>
#include <cstdio> // For sprintf

class Calculator {
public:
    // Adds two integers
    int add(int a, int b) {
        return a + b;
    }

    // Adds two doubles
    double add(double a, double b) {
        return a + b;
    }

    // Concatenates two strings - ROBUSTNESS ISSUE HERE
    std::string add(const std::string& s1, const std::string& s2) {
        // This approach is prone to buffer overflow if the combined string length
        // exceeds the fixed buffer size. Not robust for arbitrary string lengths.
        char buffer[256]; // Fixed-size buffer
        int written = snprintf(buffer, sizeof(buffer), "%s%s", s1.c_str(), s2.c_str());
        if (written >= sizeof(buffer) || written < 0) {
            // In a real application, this would indicate an error or truncation.
            // For demonstration, we'll just return the truncated part or an empty string.
            // This behavior itself is a robustness issue (truncation or unexpected empty string).
            return std::string(buffer, std::min((size_t)written, sizeof(buffer) - 1));
        }
        return std::string(buffer);
    }
};

int main() {
    Calculator calc;

    // Test int addition
    std::cout << "int add(5, 3): " << calc.add(5, 3) << std::endl; // Expected: 8
    std::cout << "int add(-10, 20): " << calc.add(-10, 20) << std::endl; // Expected: 10

    // Test double addition
    std::cout << "double add(2.5, 3.7): " << calc.add(2.5, 3.7) << std::endl; // Expected: 6.2
    std::cout << "double add(-1.1, 0.5): " << calc.add(-1.1, 0.5) << std::endl; // Expected: -0.6

    // Test string concatenation (with robustness issue)
    std::cout << "string add(\"Hello\", \"World\"): " << calc.add("Hello", "World") << std::endl; // Expected: HelloWorld
    std::cout << "string add(\"C++\", \"Programming\"): " << calc.add("C++", "Programming") << std::endl; // Expected: C++Programming

    // Test case designed to potentially trigger the robustness issue (truncation)
    std::string long_str1(150, 'a');
    std::string long_str2(150, 'b');
    std::cout << "string add(long_str1, long_str2): " << calc.add(long_str1, long_str2) << std::endl;
    // Expected to be truncated to ~255 characters, demonstrating the robustness issue.

    return 0;
}