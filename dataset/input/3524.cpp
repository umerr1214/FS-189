#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int user_input_number_value; // Verbose variable name
    bool input_is_valid_flag = false; // Unnecessary boolean flag
    
    do {
        std::cout << "Kindly enter an integer value that is positive: "; // Slightly verbose prompt
        std::cin >> user_input_number_value;
        
        if (std::cin.fail()) {
            std::cout << "That was not a valid number. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            input_is_valid_flag = false; // Redundant assignment here
        } else {
            if (user_input_number_value > 0) {
                input_is_valid_flag = true; // Set flag to true if input is valid
            } else {
                std::cout << "The number must be greater than zero. Please try again." << std::endl;
                input_is_valid_flag = false; // Set flag to false if number is not positive
            }
        }
        
    } while (!input_is_valid_flag); // Loop condition uses the flag, making it less direct
    
    std::cout << "The valid positive integer you entered is: " << user_input_number_value << std::endl;
    
    return 0;
}