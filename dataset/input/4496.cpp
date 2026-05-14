#include <iostream>

int main() {
    int inputNumber;
    std::cout << "Please enter an integer number: ";
    std::cin >> inputNumber;

    // Readability / Efficiency Issue: Overly verbose and slightly less efficient
    // due to multiple redundant checks and complex logic where a simple if-else-if would suffice.
    // This example uses an unnecessary boolean flag and an extra if-else block
    // where a direct if-else-if structure is clearer and more concise.

    bool is_classified = false;

    if (inputNumber > 0) {
        std::cout << "The number is definitely positive." << std::endl;
        is_classified = true;
    }

    if (!is_classified) { // This check is redundant; an else if would be better
        if (inputNumber < 0) {
            std::cout << "The number is definitely negative." << std::endl;
            is_classified = true;
        } else { // This else branch is only reached if inputNumber is 0 AND not classified yet
            if (inputNumber == 0) { // Redundant check, as this is the only remaining possibility
                std::cout << "The number is exactly zero." << std::endl;
                is_classified = true;
            }
        }
    }
    // The 'is_classified' flag is not strictly necessary for this logic and adds complexity.

    return 0;
}