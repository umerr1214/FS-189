#include <iostream>
#include <string>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(double a, double b) { // Semantic Error: Returns int for double addition, losing precision
        return static_cast<int>(a + b);
    }

    std::string add(std::string a, std::string b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    // Test int add
    std::cout << "Int add (5 + 3): Expected 8, Got: " << calc.add(5, 3) << std::endl;

    // Test double add
    std::cout << "Double add (5.5 + 3.3): Expected 8.8, Got: " << calc.add(5.5, 3.3) << std::endl; // Will output 8

    // Test string add
    std::cout << "String add (\"Hello\" + \"World\"): Expected HelloWorld, Got: " << calc.add("Hello", "World") << std::endl;

    return 0;
}