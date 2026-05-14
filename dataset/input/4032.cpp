#include <iostream>

int main() {
    int num1, num2, num3;
    int temp;

    std::cout << "Enter three distinct integer numbers: ";
    std::cin >> num1 >> num2 >> num3;

    std::cout << "You entered: " << num1 << " " << num2 << " " << num3 << std::endl;

    // Sorting logic with a semantic error:
    // The code correctly places the smallest number in 'num1' through the first two comparisons.
    // However, the final comparison and "swap" for 'num2' and 'num3' contains a semantic error.
    // It attempts to swap num2 and num3, but the assignment `num3 = num2;`
    // copies the *new* value of num2 (which was num3), effectively losing the original value of num2.
    // This demonstrates a misunderstanding of how to correctly perform a swap operation,
    // leading to both variables holding the same value if a swap is attempted.

    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num1 > num3) {
        temp = num1;
        num1 = num3;
        num3 = temp;
    }

    // Semantic error in the swap of num2 and num3:
    if (num2 > num3) {
        num2 = num3; // num2 now holds the original value of num3
        num3 = num2; // ERROR: num3 now also holds the (new) value of num2 (which is original num3).
                     // The original value of num2 is lost, and both end up with the same value.
    }

    std::cout << "Sorted numbers: " << num1 << " " << num2 << " " << num3 << std::endl;

    return 0;
}