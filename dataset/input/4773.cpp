#include <iostream>

int solution_main() {
    int num1, num2, num3;

    std::cout << "Enter the first integer: ";
    std::cin >> num1;
    std::cout << "Enter the second integer: ";
    std::cin >> num2;
    std::cout << "Enter the third integer: ";
    std::cin >> num3;

    // Determine the largest number using if-else if-else statements
    if (num1 >= num2 && num1 >= num3) {
        std::cout << "The largest number is: " << num1 << std::endl;
    } else if (num2 >= num1 && num2 >= num3) {
        std::cout << "The largest number is: " << num2 << std::endl;
    } else {
        // If num1 is not the largest and num2 is not the largest, then num3 must be the largest.
        std::cout << "The largest number is: " << num3 << std::endl;
    }

    return 0;
}

int main() {
    return solution_main();
}