#include <iostream>
#include <limits> // Required for std::numeric_limits<int>::min()

int main() {
    int numbers[10]; // Declare an integer array of size 10

    std::cout << "Please enter 10 integer values:" << std::endl;

    // Prompt user and read 10 integer values
    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter integer " << (i + 1) << ": ";
        // Assuming valid integer input as per the prompt.
        // For a production-grade application, input validation would be added here.
        std::cin >> numbers[i];
    }

    // Find the largest element
    // Initialize max_element with the smallest possible integer value
    // to correctly handle arrays with all negative numbers or zeros.
    int max_element = std::numeric_limits<int>::min(); 

    // Iterate through the array to find the maximum element
    for (int i = 0; i < 10; ++i) {
        if (numbers[i] > max_element) {
            max_element = numbers[i];
        }
    }

    // Print the largest element
    std::cout << "The largest element in the array is: " << max_element << std::endl;

    return 0;
}