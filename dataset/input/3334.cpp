#include <iostream>

// Function to increment an integer by 10
void increment_by_ten(int& value) {
    value += 10;
}

int main() {
    int my_value = 5;

    std::cout << "Before: " << my_value << std::endl;

    // Call the function
    increment_by_ten(my_value);

    // This line is missing a semicolon, causing a syntax error
    std::cout << "After: " << my_value << std::endl 

    return 0;
}