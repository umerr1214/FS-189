#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <iomanip> // For std::fixed and std::setprecision

class MathOperations {
public:
    int add(int val1, int val2) { // Uninformative variable names
        return val1 + val2;
    }

    int add(int i1, int i2, int i3) { // Uninformative variable names
        return i1 + i2 + i3;
    }

    double add(double d_one, double d_two) { // Uninformative variable names
        return d_one + d_two;
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
    // Integer overflow behavior (typically wraps)
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
    // Double overflow to infinity
    ss << math.add(std::numeric_limits<double>::max(), std::numeric_limits<double>::max()) << std::endl;

    return ss.str();
}

int main() {
    std::cout << run_test_cases();
    return 0;
}