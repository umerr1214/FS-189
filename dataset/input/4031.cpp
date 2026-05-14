#include <iostream>

int main() {
    int num1, num2, num3;
    int temp;

    std::cout << "Enter three distinct integer numbers: ";
    std::cin >> num1 >> num2 >> num3;

    std::cout << "You entered: " << num1 << " " << num2 << " " << num3 << std::endl;

    // Logical error: Insufficient comparisons for a full sort.
    // This code only performs two comparison/swap passes.
    // For example, if the input is "20 30 10", it will output "20 10 30" instead of "10 20 30".
    // After the first two `if` blocks, `num1` is guaranteed to be the smallest,
    // but `num2` and `num3` are not guaranteed to be in ascending order relative to each other
    // if `num1` was swapped with `num3` in the second `if` block.

    if (num1 > num2) { // Sort num1 and num2
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    if (num1 > num3) { // Sort num1 and num3 (num1 is now guaranteed smallest)
        temp = num1;
        num1 = num3;
        num3 = temp;
    }
    // Missing a final comparison between num2 and num3 to ensure they are sorted.
    // E.g., if input was 20 30 10:
    // 1. (20 > 30) is false. num1=20, num2=30, num3=10
    // 2. (20 > 10) is true. Swap num1, num3. num1=10, num2=30, num3=20
    // Result: 10 30 20 (Incorrect, should be 10 20 30)

    std::cout << "Sorted numbers: " << num1 << " " << num2 << " " << num3 << std::endl;

    return 0;
}