#include <iostream>

int main() {
    int num;
    long long factorial = 1; // Correctly initialized for 0!

    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers." << std::endl;
    } else {
        // Logical Error: If num > 0, the loop starts from i=0 and multiplies by 0, making factorial 0.
        // Also, for num=0, it correctly remains 1, but for num=1, it becomes 0.
        for (int i = 0; i <= num; ++i) {
            factorial *= i;
        }
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    }

    return 0;
}