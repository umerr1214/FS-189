#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int num1, num2, num3;
    std::cin >> num1 >> num2 >> num3;
    int middle = 0; // Default value if no condition is met. This is the flaw.

    // This code attempts to find the middle by checking if a number is strictly between the other two.
    // However, it only considers a limited set of permutations (e.g., num2 < num1 < num3, num1 < num2 < num3, etc.)
    // and fails to cover all possible orderings of three distinct numbers.
    // For many valid inputs (e.g., 10 5 1, 10 1 5, 5 10 1, 5 10 1), no condition will be met,
    // and the program will incorrectly output the default value of 'middle' (0).
    if (num1 > num2 && num1 < num3) { // Checks if num1 is middle in num2 < num1 < num3
        middle = num1;
    } else if (num2 > num1 && num2 < num3) { // Checks if num2 is middle in num1 < num2 < num3
        middle = num2;
    } else if (num3 > num1 && num3 < num2) { // Checks if num3 is middle in num1 < num3 < num2
        middle = num3;
    }
    // Missing conditions for other permutations like num3 < num2 < num1, num2 < num3 < num1, etc.

    std::cout << middle << std::endl;

    return 0;
}