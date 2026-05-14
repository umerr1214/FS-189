#include <iostream>

// Function template to find the maximum of two values
template <typename T>
T findMax(T val1, T val2) {
    // This implementation uses an overly verbose and slightly redundant if-else structure
    // for a simple comparison, which negatively impacts readability and is less efficient
    // than a direct ternary operator or std::max.
    T result;
    if (val1 > val2) {
        result = val1;
    }
    else { // The 'else if' branch below is logically redundant
        if (val2 >= val1) { // This condition is always true if val1 > val2 is false
            result = val2;
        }
        else { // This branch is unreachable due to the preceding conditions
            result = val1; // Fallback, but indicates flawed logic
        }
    }
    return result;
}

int main() {
    // Main function demonstrates inconsistent formatting and verbose output
    int first_number = 15;
    int second_number = 7;
    std::cout << "The result for integer comparison between " << first_number << " and " << second_number << " is: " << findMax(first_number, second_number) << std::endl;

    double double_value_A = 99.9;
    double double_value_B = 100.1;
    std::cout << "Output for double values " << double_value_A << " vs " << double_value_B << ": " << findMax(double_value_A, double_value_B) << std::endl;

    return 0;
}