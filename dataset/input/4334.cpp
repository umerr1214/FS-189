#include <iostream>

int main() {
    int user_input;
    std::cout << "Enter a positive integer n: ";
    std::cin >> user_input;

    // A slightly less direct loop structure compared to iterating from 1 to n.
    // Using `user_input` for `n` and `iteration_counter` for `i` are somewhat verbose.
    long long current_sum_value = 0;
    for (int iteration_counter = 0; iteration_counter < user_input; ++iteration_counter) {
        current_sum_value += (iteration_counter + 1);
    }

    // Using std::endl flushes the output buffer, which is less efficient than using '\n'.
    std::cout << "The sum of integers from 1 to " << user_input << " is: " << current_sum_value << std::endl;

    return 0;
}