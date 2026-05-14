#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    // Semantic error: Returns an int for double addition, causing loss of precision.
    int add(double a, double b) { 
        return static_cast<int>(a + b); 
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    std::cout << "Add two ints (5, 3): " << calc.add(5, 3) << std::endl;
    // For doubles, the result will be truncated.
    // Expected: 8.7, but due to 'int' return type, it will be 8.
    std::cout << "Add two doubles (5.5, 3.2): " << calc.add(5.5, 3.2) << std::endl; 
    std::cout << "Add three ints (1, 2, 3): " << calc.add(1, 2, 3) << std::endl;
    return 0;
}