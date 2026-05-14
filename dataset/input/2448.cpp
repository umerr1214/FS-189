#include <iostream>
#include <iomanip>

class MathOperations {
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
    MathOperations ops;

    // These calls are valid
    std::cout << "Sum of 5 and 10 (int): " << ops.add(5, 10) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Sum of 5.5 and 10.5 (double): " << ops.add(5.5, 10.5) << std::endl;
    std::cout << "Sum of 1, 2, and 3 (int): " << ops.add(1, 2, 3) << std::endl;

    // Semantic error: Attempting to call an `add` method with four integer arguments.
    // No such overload exists in the MathOperations class.
    std::cout << "Sum of 1, 2, 3, and 4 (int): " << ops.add(1, 2, 3, 4) << std::endl;

    return 0;
}