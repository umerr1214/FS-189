#include <iostream>

int main() {
    int num1, num2, num3;

    std::cout << "Enter three integers: ";
    std::cin >> num1 >> num2 >> num3;

    int largest_val;

    // Semantic Error: Using the assignment operator '=' instead of the comparison operator '=='
    // in the first 'if' condition.
    // This assigns the value of num2 to num1, and then evaluates the new value of num1 (which is num2).
    // The branch is taken if num2 is non-zero, and skipped if num2 is zero.
    // This fundamentally alters the value of num1 and leads to incorrect logic.
    if (num1 = num2) { // num1 is assigned num2's value. Condition is true if num2 != 0.
        // Inside this block, 'num1' now holds the original value of 'num2'.
        if (num1 > num3) { // Compares original num2 (now in num1) with num3.
            largest_val = num1; // largest_val gets original num2.
        } else {
            largest_val = num3;
        }
    } else if (num1 > num3) { // This branch is only reached if num2 was 0.
                              // In this case, num1 was assigned 0, so this condition is '0 > num3'.
                              // Only true if num3 is negative.
        largest_val = num1; // largest_val gets 0.
    } else { // This branch is reached if num2 was 0 AND num3 >= 0.
        largest_val = num3;
    }

    std::cout << "The largest number is: " << largest_val << std::endl;

    return 0;
}