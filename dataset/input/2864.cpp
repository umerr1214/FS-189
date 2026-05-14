#include <iostream>
#include <string>
#include <vector>
#include <numeric> // For std::accumulate

class Calculator {
public:
    // Adds two integers - Readability Issue (bitwise ops)
    int add(int a, int b) {
        // This uses bitwise operations for addition, which is functionally correct
        // but significantly less readable and less intuitive than a simple '+' operator
        // for standard integer addition.
        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }

    // Adds two doubles - Efficiency/Readability Issue (unnecessary std::accumulate)
    double add(double a, double b) {
        // Using std::accumulate for just two numbers is overly verbose and less efficient
        // than a direct addition. It creates a temporary vector unnecessarily.
        std::vector<double> numbers = {a, b};
        return std::accumulate(numbers.begin(), numbers.end(), 0.0);
    }

    // Concatenates two strings - Efficiency Issue (character-by-character append)
    std::string add(const std::string& s1, const std::string& s2) {
        // Concatenating character by character using operator+= can be inefficient
        // due to potential multiple reallocations of the string buffer.
        std::string result = "";
        for (char c : s1) {
            result += c;
        }
        for (char c : s2) {
            result += c;
        }
        return result;
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

    // Test string concatenation
    std::cout << "string add(\"Hello\", \"World\"): " << calc.add("Hello", "World") << std::endl; // Expected: HelloWorld
    std::cout << "string add(\"C++\", \"Programming\"): " << calc.add("C++", "Programming") << std::endl; // Expected: C++Programming
    std::cout << "string add(\"\", \"Empty\"): " << calc.add("", "Empty") << std::endl; // Expected: Empty

    return 0;
}