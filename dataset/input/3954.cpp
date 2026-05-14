#include <iostream>

// Semantic Error: The function uses pass-by-reference (int& a, int& b)
// instead of pass-by-value (int a, int b) as specified in the problem.
// While the algorithm correctly calculates GCD, it modifies the original
// input variables in the caller's scope, which is a violation of the
// problem's explicit instruction and can lead to unexpected side effects
// or misleading output.
int findGCD(int& a, int& b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    std::cout << "Enter two positive integers: ";
    std::cin >> num1 >> num2;

    if (num1 <= 0 || num2 <= 0) {
        std::cout << "Please enter positive integers." << std::endl;
        return 1;
    }

    // Calling findGCD with num1 and num2 will modify their values
    int result = findGCD(num1, num2);
    // The output here will display the *modified* values of num1 and num2,
    // which is misleading as they are no longer the original inputs.
    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << std::endl;

    return 0;
}