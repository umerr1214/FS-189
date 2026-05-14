#include <iostream>

// Function to increment an integer by 10
// Semantic error: 'value' is a const reference, but the function attempts to modify it.
void increment_by_ten(const int& value) {
    value += 10; // This line will cause a compilation error because 'value' is const
}

int main() {
    int my_value = 5;

    std::cout << "Before: " << my_value << std::endl;

    // Call the function
    increment_by_ten(my_value);

    std::cout << "After: " << my_value << std::endl;

    return 0;
}