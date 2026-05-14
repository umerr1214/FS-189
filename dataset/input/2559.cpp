#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <iomanip> // For std::fixed and std::setprecision

class MathOperations {
public:
    // Adds two integers and returns their sum.
    // Uses clear variable names for improved readability.
    int add(int num1, int num2) {
        return num1 + num2;
    }

    // Adds three integers and returns their sum.
    // Uses clear variable names for improved readability.
    int add(int val1, int val2, int val3) {
        return val1 + val2 + val3;
    }

    // Adds two double-precision floating-point numbers and returns their sum.
    // Uses clear variable names for improved readability.
    double add(double double1, double double2) {
        return double1 + double2;
    }
};

std::string run_test_cases() {
    std::stringstream ss;
    MathOperations math;

    // Test add(int, int)
    ss << math.add(5, 7) << std::endl;
    ss << math.add(-10, 3) << std::endl;
    ss << math.add(0, 0) << std::endl;
    ss << math.add(1000000, 2000000) << std::endl;
    // Integer overflow behavior (typically wraps on most systems for signed int)
    ss << math.add(2000000000, 2000000000) << std::endl; 
    ss << math.add(std::numeric_limits<int>::max(), 1) << std::endl;

    // Test add(int, int, int)
    ss << math.add(1, 2, 3) << std::endl;
    ss << math.add(-5, 0, 5) << std::endl;
    ss << math.add(100000, 200000, 300000) << std::endl;
    // Integer overflow behavior (typically wraps)
    ss << math.add(1000000000, 1000000000, 1000000000) << std::endl;
    ss << math.add(std::numeric_limits<int>::max(), 1, 1) << std::endl;

    // Test add(double, double)
    ss << std::fixed << std::setprecision(6); // Set precision for double outputs
    ss << math.add(1.5, 2.5) << std::endl;
    ss << math.add(-3.0, 1.2) << std::endl;
    ss << math.add(0.0, 0.0) << std::endl;
    ss << math.add(123.456, 789.012) << std::endl;
    ss << math.add(0.000001, 0.000002) << std::endl;
    // Double overflow to infinity (standard behavior)
    ss << math.add(std::numeric_limits<double>::max(), std::numeric_limits<double>::max()) << std::endl;

    return ss.str();
}

int main() {
    std::cout << run_test_cases();
    return 0;
}