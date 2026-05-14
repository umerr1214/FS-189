#include <iostream>

int main() {
    long long input_val; // Variable name is slightly verbose for its simple role.
    std::cout << "Enter non-negative: "; // Prompt is short and less user-friendly.
    std::cin >> input_val;

    int counter_for_digits = 0; // Variable name is slightly verbose.

    // Readability / Efficiency Issue:
    // 1. Uses a `while(true)` loop with an explicit `break`, which is generally
    //    less idiomatic and potentially less readable than a direct `while (condition)` loop
    //    (e.g., `while (temp_num > 0)`).
    // 2. An unnecessary temporary variable `temp_num` is created. The original `input_val`
    //    could have been used directly if its original value was not needed later.
    // 3. The explicit `if (temp_num == 0)` check inside the `while(true)` loop is redundant,
    //    as the loop condition `while (temp_num > 0)` would naturally handle termination
    //    more efficiently and clearly.

    if (input_val == 0) {
        counter_for_digits = 1;
    } else {
        long long temp_num = input_val; // Unnecessary copy
        while (true) { // Less idiomatic loop structure
            if (temp_num == 0) { // Redundant check for loop termination
                break;
            }
            temp_num /= 10;
            counter_for_digits++;
        }
    }

    std::cout << "Number of digits is: " << counter_for_digits << std::endl;

    return 0;
}