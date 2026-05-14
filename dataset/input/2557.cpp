#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits> // Required for INT_MAX
#include <iomanip> // For std::fixed and std::setprecision

class MathOperations {
public:
    int add(int a, int b) {
        // Robustness Issue: Potential integer overflow if sum exceeds INT_MAX.
        // C++ standard defines this as undefined behavior, but it often wraps.
        // A robust solution might use long long or check for overflow.
        return a + b;
    }

    int add(int a, int b, int c) {
        // Robustness Issue: Potential integer overflow if sum exceeds INT_MAX.
        return a + b + c;
    }

    double add(double a, double b) {
        // Double precision numbers handle overflow by returning 'inf',
        // which is standard but could be considered a robustness concern if
        // the application requires specific handling of such extreme values.
        return a + b;
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
    // Robustness test cases: potential integer overflow
    // Mathematical sum: 4000000000 (exceeds INT_MAX = 2147483647)
    ss << math.add(2000000000, 2000000000) << std::endl; 
    // Mathematical sum: INT_MAX + 1 = 2147483648 (exceeds INT_MAX)
    ss << math.add(std::numeric_limits<int>::max(), 1) << std::endl;

    // Test add(int, int, int)
    ss << math.add(1, 2, 3) << std::endl;
    ss << math.add(-5, 0, 5) << std::endl;
    ss << math.add(100000, 200000, 300000) << std::endl;
    // Robustness test cases: potential integer overflow
    // Mathematical sum: 3000000000 (exceeds INT_MAX)
    ss << math.add(1000000000, 1000000000, 1000000000) << std::endl;
    // Mathematical sum: INT_MAX + 1 + 1 = 2147483649 (exceeds INT_MAX)
    ss << math.add(std::numeric_limits<int>::max(), 1, 1) << std::endl;

    // Test add(double, double)
    ss << std::fixed << std::setprecision(6); // Set precision for double outputs
    ss << math.add(1.5, 2.5) << std::endl;
    ss << math.add(-3.0, 1.2) << std::endl;
    ss << math.add(0.0, 0.0) << std::endl;
    ss << math.add(123.456, 789.012) << std::endl;
    ss << math.add(0.000001, 0.000002) << std::endl;
    // Robustness test case: potential double overflow to infinity
    // Mathematical sum: 2 * DBL_MAX, which is 'inf'
    ss << math.add(std::numeric_limits<double>::max(), std::numeric_limits<double>::max()) << std::endl;

    return ss.str();
}

int main() {
    std::cout << run_test_cases();
    return 0;
}