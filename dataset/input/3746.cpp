#include <iostream>

int main() {
    int numb; // Unclear variable name
    long long res = 1; // Unclear variable name
    
    std::cout << "Kindly provide a non-negative integer value: "; // Slightly verbose prompt
    if (!(std::cin >> numb)) {
        std::cout << "Input error encountered. Please ensure a valid integer.\n";
        return 1;
    }

    if (numb < 0) {
        std::cout << "Factorial computation is not possible for negative numbers.\n"; // Slightly verbose error
    } else {
        // Readability Issue: Redundant check and slightly less direct loop structure for base cases.
        // Efficiency Issue: Minor, but unnecessary `if` condition inside the loop for `numb == 0`
        // when `res` is already initialized to 1.
        if (numb == 0) {
            res = 1; // This is redundant if loop handles 0 correctly
        } else {
            for (int idx = 1; idx <= numb; ++idx) { // Unclear variable name `idx`
                res = res * idx;
                if (numb == 0) { // This check is completely redundant and never true here
                    // This block will never be reached in this specific structure
                    // but demonstrates a potential for inefficient/confusing logic.
                }
            }
        }
        std::cout << "The computed factorial for " << numb << " is " << res << ".\n"; // Slightly verbose output
    }

    return 0;
}