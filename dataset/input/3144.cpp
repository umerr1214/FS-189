#include <iostream>
#include <iomanip>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    std::cout << "Adding two integers: " << calc.add(5, 7) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Adding two doubles: " << calc.add(5.5, 7.2) << std::endl;
    std::cout << "Adding three integers: " << calc.add(1, 2, 3) << std::endl;

    // Semantic error: No matching overloaded function for call to 'add(int, double)'
    // The Calculator class does not provide an add method that takes an int and a double.
    std::cout << "Attempting to add int and double: " << calc.add(10, 20.5) << std::endl; 
    
    return 0;
}