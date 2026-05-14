#include <iostream>

// recursive_gcd_calculator function calculates GCD using recursive Euclidean algorithm.
// This approach, while mathematically correct, can be less efficient for very large inputs
// compared to an iterative solution due to function call overhead and potential stack depth.
int recursive_gcd_calculator(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return recursive_gcd_calculator(y, x % y);
    }
}

int main() {
    int a, b; // Poor variable names

    std::cout << "Enter first number: ";
    std::cin >> a; // No input validation
    std::cout << "Enter second number: ";
    std::cin >> b; // No input validation

    // Assuming positive inputs for simplicity in this version.
    // If a or b were non-positive, the recursive function might behave unexpectedly
    // or lead to an infinite recursion if not handled.
    if (a < 0) a = -a; // Basic attempt to handle negative, but not robust.
    if (b < 0) b = -b;

    if (a == 0 && b == 0) {
        std::cout << "GCD is undefined for (0, 0)." << std::endl;
    } else if (a == 0) {
        std::cout << "GCD of " << a << " and " << b << " is: " << b << std::endl;
    } else if (b == 0) {
        std::cout << "GCD of " << a << " and " << b << " is: " << a << std::endl;
    } else {
        int result = recursive_gcd_calculator(a, b);
        std::cout << "GCD of " << a << " and " << b << " is: " << result << std::endl;
    }

    return 0;
}