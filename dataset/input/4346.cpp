#include <iostream>

int main() {
    int my_array[5]; // Declare an array of 5 integers

    // Prompt user to enter values
    for (int i = 0; i < 5; ++i) { // Loop 5 times
        std::cout << "Give integer #" << i + 1 << ": ";
        std::cin >> my_array[i];
    }

    std::cout << "Here are the numbers in reverse:" << std::endl;

    // Print elements in reverse order using a slightly less direct approach
    for (int k = 0; k < 5; ++k) { // Loop 5 times
        std::cout << my_array[4 - k] << " "; // Access element from the end
    }
    std::cout << std::endl;

    return 0;
}