#include <iostream>

int main() {
    int num1, num2, num3;

    std::cout << "Enter three distinct integer numbers:" << std::endl;
    std::cout << "Number 1: ";
    std::cin >> num1;
    std::cout << "Number 2: ";
    std::cin >> num2;
    std::cout << "Number 3: ";
    std::cin >> num3;

    // Robustness Issue:
    // 1. No check for std::cin.fail() after input. If user enters non-integer,
    //    the input stream will enter a failed state, and num2/num3 might remain uninitialized
    //    or take on default values (e.g., 0), leading to incorrect or undefined behavior.
    // 2. It does not enforce distinctness as required by the prompt; it will sort
    //    non-distinct numbers without warning or re-prompting.

    // Sorting logic (simple bubble-sort like swaps for 3 numbers)
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) {
        int temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num1 > num2) { // One more check for num1 and num2 after num2 might have moved
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    std::cout << "Sorted numbers: " << num1 << " " << num2 << " " << num3 << std::endl;

    return 0;
}