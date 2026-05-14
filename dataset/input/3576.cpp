#include <iostream>
#include <algorithm> // Required for std::max

int main() {
    int num1, num2, num3;
    std::cout << "Enter three integers: ";
    std::cin >> num1 >> num2 >> num3;

    int largest = num1; // Initialize 'largest'
    largest = std::max(num1, num2); // 'largest' now holds the max of num1 and num2
    // Semantic error: The return value of std::max(largest, num3) is not assigned back to 'largest'.
    // The function call computes the maximum but its result is discarded, leaving 'largest' unchanged.
    // This means if num3 is the overall largest number, 'largest' will incorrectly retain max(num1, num2).
    std::max(largest, num3); // Result of this call is ignored

    std::cout << "The largest number is: " << largest << std::endl;

    return 0;
}