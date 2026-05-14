#include <iostream>
#include <iomanip>

class MathOperations {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    double add(double a, double b) {
        // Semantic Error: Implicitly truncates double arguments to integers before adding.
        // This loses precision and violates the semantic intent of adding double-precision numbers.
        return static_cast<double>(static_cast<int>(a) + static_cast<int>(b));
    }
};

int main() {
    MathOperations mo;

    // Test add(int, int)
    std::cout << "add(5, 3) = " << mo.add(5, 3) << std::endl;

    // Test add(int, int, int)
    std::cout << "add(1, 2, 3) = " << mo.add(1, 2, 3) << std::endl;

    // Test add(double, double)
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "add(2.5, 3.5) = " << mo.add(2.5, 3.5) << std::endl;
    std::cout << "add(10.1, 0.9) = " << mo.add(10.1, 0.9) << std::endl;

    return 0;
}