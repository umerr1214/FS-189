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

    // Readability / Efficiency Issue:
    // This sorting logic is correct but uses a highly nested and verbose
    // if-else structure, explicitly checking all 6 permutations to determine
    // the sorted order. This makes the code less readable and potentially
    // less efficient (more complex branching, larger code size) than a simpler
    // approach like a series of conditional swaps.
    // It also lacks input validation for non-integer or non-distinct values,
    // though that's not the primary error type for this category.

    int sorted1, sorted2, sorted3;

    if (num1 <= num2 && num1 <= num3) { // num1 is the smallest
        sorted1 = num1;
        if (num2 <= num3) {
            sorted2 = num2;
            sorted3 = num3;
        } else { // num3 < num2
            sorted2 = num3;
            sorted3 = num2;
        }
    } else if (num2 <= num1 && num2 <= num3) { // num2 is the smallest
        sorted1 = num2;
        if (num1 <= num3) {
            sorted2 = num1;
            sorted3 = num3;
        } else { // num3 < num1
            sorted2 = num3;
            sorted3 = num1;
        }
    } else { // num3 is the smallest
        sorted1 = num3;
        if (num1 <= num2) {
            sorted2 = num1;
            sorted3 = num2;
        } else { // num2 < num1
            sorted2 = num2;
            sorted3 = num1;
        }
    }

    std::cout << "Sorted numbers: " << sorted1 << " " << sorted2 << " " << sorted3 << std::endl;

    return 0;
}