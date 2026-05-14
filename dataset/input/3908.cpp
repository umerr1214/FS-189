#include <iostream>
#include <string> // Unnecessary include for this problem
#include <limits> // Required for std::numeric_limits

int main() {
    int val; // Generic variable name, not very descriptive
    bool input_ok = false;

    do {
        std::cout << "Please provide a number: "; // Less specific prompt
        std::cin >> val;

        if (std::cin.fail()) {
            std::cout << "That was not a valid number. Try again." << std::endl; // Inconsistent use of std::endl
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            input_ok = false;
        } else {
            // Overly verbose and nested conditional for range checking
            if (val >= 1) {
                if (val <= 7) {
                    input_ok = true;
                } else {
                    std::cout << "The number is too high. It must be between 1 and 7." << std::endl;
                    input_ok = false;
                }
            } else {
                std::cout << "The number is too low. It must be between 1 and 7." << std::endl;
                input_ok = false;
            }
        }
    } while (!input_ok);

    switch (val) {
        case 1:
            std::cout << "It's Monday." << std::endl; // Inconsistent output style with 'It's'
            break;
        case 2:
            std::cout << "It's Tuesday." << std::endl;
            break;
        case 3:
            std::cout << "It's Wednesday." << std::endl;
            break;
        case 4:
            std::cout << "It's Thursday." << std::endl;
            break;
        case 5:
            std::cout << "It's Friday." << std::endl;
            break;
        case 6:
            std::cout << "It's Saturday." << std::endl;
            break;
        case 7:
            std::cout << "It's Sunday." << std::endl;
            break;
        default: // This case should not be reached due to the input validation loop
            std::cout << "An unexpected error occurred with the day value." << std::endl;
            break;
    }

    return 0;
}