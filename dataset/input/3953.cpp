#include <iostream>

// Function to calculate GCD using Euclidean algorithm (pass by value)
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        // Logical Error: 'a' is incorrectly updated with the new 'b' (remainder)
        // instead of the original 'b' (stored in 'temp').
        // This breaks the Euclidean algorithm's state transition.
        a = b;
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

    int result = findGCD(num1, num2);
    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << std::endl;

    return 0;
}