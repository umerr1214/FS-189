#include <iostream>

int main() {
    int num1, num2, num3;
    std::cout << "Enter three integers: ";
    std::cin >> num1 >> num2 >> num3;

    int largest = num1;

    if (num2 > num1) { // Compares num2 with num1
        largest = num2;
    }
    // Logical error: This condition incorrectly compares num3 with num2.
    // It should compare num3 with the current `largest` value, which could be num1 or num2.
    // For example, if num1=20, num2=5, num3=10, the correct largest is 20.
    // But this logic would set largest to 10 because (10 > 5) is true, ignoring num1=20.
    if (num3 > num2) {
        largest = num3;
    }

    std::cout << "The largest number is: " << largest << std::endl;

    return 0;
}