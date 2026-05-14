#include <iostream>
#include <iomanip>
#include <limits> // For demonstrating potential overflow

class Calculator {
public:
    // Adds two integers, susceptible to overflow if sum exceeds INT_MAX
    int add(int a, int b) {
        return a + b;
    }

    // Adds two doubles, but returns a float, leading to precision loss
    float add(double a, double b) {
        return static_cast<float>(a + b);
    }

    // Adds three integers, susceptible to overflow
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    // Demonstrate calling each version
    int int_val1 = 10;
    int int_val2 = 20;
    int int_val3 = 30;

    double double_val1 = 10.123456789;
    double double_val2 = 20.987654321;

    // Call int, int version
    int sum_int = calc.add(int_val1, int_val2);
    std::cout << "Int sum: " << sum_int << '\n';

    // Call double, double version (result will be float)
    float sum_double_as_float = calc.add(double_val1, double_val2);
    std::cout << std::fixed << std::setprecision(8);
    std::cout << "Double sum (as float): " << sum_double_as_float << '\n';

    // Call int, int, int version
    int sum_three_int = calc.add(int_val1, int_val2, int_val3);
    std::cout << "Three int sum: " << sum_three_int << '\n';

    // Example of potential integer overflow (not directly printed, but possible)
    // int large_int1 = std::numeric_limits<int>::max() - 10;
    // int large_int2 = 20;
    // int overflow_sum = calc.add(large_int1, large_int2);
    // std::cout << "Overflow potential sum: " << overflow_sum << '\n'; // Will wrap around

    return 0;
}