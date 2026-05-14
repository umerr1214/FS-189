#include <iostream>
#include <limits> // Required for std::numeric_limits

int user_main() {
    int the_user_input_value_for_positive_check; // Overly long and verbose variable name
    bool condition_met; // Unnecessary boolean flag to control the loop

    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> the_user_input_value_for_positive_check;

        if (std::cin.fail() || the_user_input_value_for_positive_check <= 0) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            condition_met = false; // Set flag to continue loop
        } else {
            condition_met = true; // Set flag to exit loop
        }
    } while (!condition_met); // Loop based on the unnecessary flag

    std::cout << "You entered: " << the_user_input_value_for_positive_check << std::endl;
    return 0;
}

int main() {
    return user_main();
}