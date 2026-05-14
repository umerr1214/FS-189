#include <iostream>

// Class design with a semantic error
class MathOperations {
public:
    // Method to multiply two integers - correctly public
    int multiply(int a, int b) {
        return a * b;
    }

private: // SEMANTIC ERROR: This method is declared private, but the question requires it to be public.
    // Method to multiply three double values
    double multiply(double a, double b, double c) {
        return a * b * c;
    }
};

int main() {
    MathOperations math;

    // Test integer multiplication (this will work)
    int int_val1 = 5;
    int int_val2 = 10;
    int int_result = math.multiply(int_val1, int_val2);
    std::cout << "Product of " << int_val1 << " and " << int_val2 << " (int): " << int_result << std::endl;

    // Attempt to test double multiplication (this will cause a semantic error at compile time)
    double double_val1 = 2.5;
    double double_val2 = 3.0;
    double double_val3 = 4.0;
    // The following line will cause a compiler error because multiply(double, double, double) is private.
    // double double_result = math.multiply(double_val1, double_val2, double_val3);
    // std::cout << "Product of " << double_val1 << ", " << double_val2 << ", and " << double_val3 << " (double): " << double_result << std::endl;

    return 0;
}