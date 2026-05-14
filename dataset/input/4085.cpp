#include <iostream>

// Function to calculate base raised to exponent
double power(double base, int exponent)
{
    double result = 1.0;
    // LOGICAL ERROR: The loop condition 'i <= exponent' causes an extra multiplication.
    // For exponent 'n', it should iterate 'n' times (from i=0 to i<n).
    // This loop iterates 'n+1' times (from i=0 to i=n).
    for (int i = 0; i <= exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    // Test cases
    std::cout << "2.0^3 = " << power(2.0, 3) << std::endl; // Expected: 8.0, Actual: 16.0
    std::cout << "5.0^0 = " << power(5.0, 0) << std::endl; // Expected: 1.0, Actual: 5.0
    std::cout << "10.0^1 = " << power(10.0, 1) << std::endl; // Expected: 10.0, Actual: 100.0
    std::cout << "0.0^5 = " << power(0.0, 5) << std::endl; // Expected: 0.0, Actual: 0.0 (0 raised to any positive power is 0)
    std::cout << "1.5^2 = " << power(1.5, 2) << std::endl; // Expected: 2.25, Actual: 3.375
    std::cout << "0.5^4 = " << power(0.5, 4) << std::endl; // Expected: 0.0625, Actual: 0.03125
    std::cout << "1.0^100 = " << power(1.0, 100) << std::endl; // Expected: 1.0, Actual: 1.0 (1 raised to any power is 1)

    return 0;
}