#include <iostream>

int main() {
    int num1, num2, num3;

    std::cout << "Enter three integers: ";
    std::cin >> num1 >> num2 >> num3;

    // Logical Error: This logic fails when the two largest numbers are equal.
    // For example, if input is 10 10 5, it will print 5 (incorrect, should be 10).
    // If input is 10 5 10, it will print 5 (incorrect, should be 10).
    // If input is 5 10 10, it will print 5 (incorrect, should be 10).
    if (num1 > num2 && num1 > num3) {
        std::cout << "The largest number is: " << num1 << std::endl;
    } else if (num2 > num1 && num2 > num3) {
        std::cout << "The largest number is: " << num2 << std::endl;
    } else {
        // This 'else' block incorrectly assumes num3 is the largest if the above conditions are false.
        // It fails to consider cases where num1 or num2 could be equal to num3 and be the largest,
        // or where num1 == num2 and they are the largest.
        std::cout << "The largest number is: " << num3 << std::endl;
    }

    return 0;
}