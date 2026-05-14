#include <iostream>
#include <limits> // For INT_MAX
#include <iomanip> // For double precision (or lack thereof in this case)

class MathOperations {
public:
    // Adds two integers. Returns int, which can overflow for very large sums.
    int add(int a, int b) {
        return a + b;
    }

    // Adds two doubles. Returns double. Output precision is not explicitly set.
    double add(double a, double b) {
        return a + b;
    }

    // Adds three integers. Returns int, which can overflow for very large sums.
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    MathOperations ops;

    // Demonstrate integer addition - using values that are large but just fit,
    // to highlight the potential for overflow if inputs were slightly larger.
    // The lack of explicit overflow handling or return type change (e.g., to long long)
    // is a robustness issue.
    int int_val1 = 2147483640; // INT_MAX is 2147483647
    int int_val2 = 5;
    std::cout << "Adding two integers (" << int_val1 << " + " << int_val2 << "): " << ops.add(int_val1, int_val2) << std::endl;

    // Demonstrate double addition - default precision for output might not always be robust.
    double double_val1 = 0.1;
    double double_val2 = 0.2;
    std::cout << "Adding two doubles (" << double_val1 << " + " << double_val2 << "): " << ops.add(double_val1, double_val2) << std::endl;

    // Demonstrate three integer addition - using values that sum close to INT_MAX,
    // highlighting the potential for overflow.
    int int_val3 = 700000000;
    int int_val4 = 800000000;
    int int_val5 = 600000000;
    std::cout << "Adding three integers (" << int_val3 << " + " << int_val4 << " + " << int_val5 << "): " << ops.add(int_val3, int_val4, int_val5) << std::endl;

    return 0;
}