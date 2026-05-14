#include <iostream> // Required for input/output operations
#include <vector>   // Included for common C++ practice, though a C-style array is used
#include <numeric>  // Included for common C++ practice, not directly used in this simple loop

int main() {
    // Initialize a 1D integer array with 10 elements
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Initialize variables for sum and product with descriptive names
    long long sumOfEvenNumbers = 0;
    // Initialize product to 1. This is crucial for correctness, as the product of an empty set is 1.
    long long productOfOddNumbers = 1;

    // Iterate through the array using a range-based for loop for clear and concise iteration
    for (int number : numbers) {
        if (number % 2 == 0) {
            sumOfEvenNumbers += number;
        } else {
            productOfOddNumbers *= number;
        }
    }

    // Display the calculated results with clear labels and std::endl for flushing output
    std::cout << "Sum of even numbers: " << sumOfEvenNumbers << std::endl;
    std::cout << "Product of odd numbers: " << productOfOddNumbers << std::endl;

    return 0;
}