#include <iostream>

int main() {
    long long a_sum_accumulator = 0; // Readability Issue: Poor variable naming
    int input_val;                   // Readability Issue: Poor variable naming

    while (true) {
        std::cin >> input_val;

        // This program is not robust against non-integer input.
        // If std::cin fails, 'input_val' might retain its previous value,
        // and std::cin's failbit will be set. Subsequent reads will also fail,
        // potentially leading to an infinite loop if 'input_val' is not 0 and the error state is not cleared.
        // For 'correctness = 9', we assume valid integer input for the core logic,
        // but acknowledge this is a robustness flaw not addressed here.

        if (input_val == 0) {
            goto end_of_input; // Readability Issue: Use of 'goto' statement for loop control
        }
        
        a_sum_accumulator = a_sum_accumulator + input_val; // Readability Issue: Redundant variable prefix and verbose addition
    }

end_of_input: // Target for goto statement
    std::cout << a_sum_accumulator << std::endl; // Print the final sum
    return 0;
}