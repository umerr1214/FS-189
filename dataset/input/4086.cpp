#include <iostream>
#include <iomanip> // For std::setprecision

// Function to calculate base raised to exponent
double power(double base, int exponent)
{
    // SEMANTIC ERROR: Using 'float' for intermediate calculation and result storage
    // when 'double' is specified for the function's parameters and return type.
    // This can lead to loss of precision, even though the final return type is cast to double.
    float result = 1.0f;
    for (int i = 0; i < exponent; ++i) {
        result *= base; // 'base' (double) is converted to float before multiplication
    }
    return result; // 'result' (float) is implicitly converted to double upon return
}

int main() {
    // Test cases
    std::cout << std::fixed << std::setprecision(10); // Set precision for output
    std::cout << "2.0^3 = " << power(2.0, 3) << std::endl;
    std::cout << "5.0^0 = " << power(5.0, 0) << std::endl;
    std::cout << "10.0^1 = " << power(10.0, 1) << std::endl;
    std::cout << "0.0^5 = " << power(0.0, 5) << std::endl;
    std::cout << "1.5^2 = " << power(1.5, 2) << std::endl;
    std::cout << "0.5^4 = " << power(0.5, 4) << std::endl;
    std::cout << "1.0^100 = " << power(1.0, 100) << std::endl;
    // Example that might expose precision issues more clearly
    std::cout << "0.1^3 = " << power(0.1, 3) << std::endl; // Expected: 0.001
    std::cout << "1.0/3.0^2 = " << power(1.0/3.0, 2) << std::endl; // Expected: 0.1111111111

    return 0;
}