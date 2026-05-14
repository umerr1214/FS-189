#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    // Semantic error: The method for adding two doubles returns an int,
    // truncating any fractional part of the sum.
    // The question implies returning the sum of doubles should retain double precision.
    int add(double a, double b) {
        return static_cast<int>(a + b);
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    std::cout << "Sum of 5 and 7: " << calc.add(5, 7) << std::endl;
    std::cout << std::fixed << std::setprecision(1); // To format double output
    std::cout << "Sum of 5.5 and 7.7: " << calc.add(5.5, 7.7) << std::endl; // Expected 13.2, actual 13.0
    std::cout << "Sum of 1, 2, and 3: " << calc.add(1, 2, 3) << std::endl;
    return 0;
}