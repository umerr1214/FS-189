#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class Calculator3068 {
public:
    // Readability Issue: Poorly named variables (v1, v2) reduce clarity.
    int add(int v1, int v2) {
        return v1 + v2;
    }

    // Readability/Efficiency Issue: This method calls another 'add' method.
    // While functionally correct, it's less direct than a simple sum (v1 + v2 + v3)
    // and introduces minor, unnecessary function call overhead, slightly impacting efficiency.
    int add(int v1, int v2, int v3) {
        return add(v1, v2) + v3;
    }

    // Readability Issue: Another set of cryptic variable names (d1, d2).
    double add(double d1, double d2) {
        return d1 + d2;
    }
};

int main() {
    Calculator3068 calculator;

    std::cout << "Adding two integers (10, 20): " << calculator.add(10, 20) << std::endl;
    std::cout << "Adding two integers (-5, 15): " << calculator.add(-5, 15) << std::endl;

    std::cout << "Adding three integers (1, 2, 3): " << calculator.add(1, 2, 3) << std::endl;
    std::cout << "Adding three integers (100, -50, 20): " << calculator.add(100, -50, 20) << std::endl;

    std::cout << std::fixed << std::setprecision(1); // For consistent double output
    std::cout << "Adding two doubles (10.5, 20.3): " << calculator.add(10.5, 20.3) << std::endl;
    std::cout << "Adding two doubles (-2.5, 7.0): " << calculator.add(-2.5, 7.0) << std::endl;
    std::cout << std::setprecision(6); // Reset precision to default

    return 0;
}