#include <iostream>

// Function to calculate base raised to exponent
double power(double base, int exponent)
{
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result // SYNTAX ERROR: Missing semicolon here
}

int main() {
    // Test cases
    std::cout << "2.0^3 = " << power(2.0, 3) << std::endl;
    std::cout << "5.0^0 = " << power(5.0, 0) << std::endl;
    std::cout << "10.0^1 = " << power(10.0, 1) << std::endl;
    std::cout << "0.0^5 = " << power(0.0, 5) << std::endl;
    std::cout << "1.5^2 = " << power(1.5, 2) << std::endl;
    std::cout << "0.5^4 = " << power(0.5, 4) << std::endl;
    std::cout << "1.0^100 = " << power(1.0, 100) << std::endl;

    return 0;
}