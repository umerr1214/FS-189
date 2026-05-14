#include <iostream>

int user_main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> num;
        // Robustness issue: Does not handle non-integer input.
        // If non-integer is entered, std::cin enters a fail state,
        // num's value is unchanged (potentially garbage or 0 if initialized),
        // and the input buffer is not cleared. This will lead to an infinite loop.
    } while (num <= 0); // Loop continues if num is not positive
    std::cout << "You entered: " << num << std::endl;
    return 0;
}

int main() {
    return user_main();
}