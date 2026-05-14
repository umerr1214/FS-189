#include <iostream>

// Function to increment an integer by 10 (intended)
void increment_by_ten(int& value) {
    // Logical error: increments by 5 instead of 10
    value += 5; 
}

int main() {
    int my_value = 5;

    std::cout << "Before: " << my_value << std::endl;

    // Call the function
    increment_by_ten(my_value);

    std::cout << "After: " << my_value << std::endl;

    return 0;
}