#include <iostream>
#include <string>
#include <vector> // Not strictly needed for this solution but good for general C++ programs

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

    // Concatenates two std::string arguments
    std::string add(const std::string& s1, const std::string& s2) {
        return s1 + s2; // Standard and efficient way to concatenate std::strings
    }
};

int main() {
    Calculator calc;

    // Test int addition
    std::cout << "int add(5, 3): " << calc.add(5, 3) << std::endl; // Expected: 8
    std::cout << "int add(-10, 20): " << calc.add(-10, 20) << std::endl; // Expected: 10
    std::cout << "int add(0, 0): " << calc.add(0, 0) << std::endl; // Expected: 0

    // Test double addition
    std::cout << "double add(2.5, 3.7): " << calc.add(2.5, 3.7) << std::endl; // Expected: 6.2
    std::cout << "double add(-1.1, 0.5): " << calc.add(-1.1, 0.5) << std::endl; // Expected: -0.6
    std::cout << "double add(100.0, 200.5): " << calc.add(100.0, 200.5) << std::endl; // Expected: 300.5

    // Test string concatenation
    std::cout << "string add(\"Hello\", \"World\"): " << calc.add("Hello", "World") << std::endl; // Expected: HelloWorld
    std::cout << "string add(\"C++\", \"Programming\"): " << calc.add("C++", "Programming") << std::endl; // Expected: C++Programming
    std::cout << "string add(\"\", \"Empty\"): " << calc.add("", "Empty") << std::endl; // Expected: Empty
    std::cout << "string add(\"First\", \"\"): " << calc.add("First", "") << std::endl; // Expected: First

    return 0;
}