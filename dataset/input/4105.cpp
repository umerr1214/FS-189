#include <iostream>
#include <numeric> // Not strictly needed for a simple loop, but good practice

// Function to calculate the average of elements in an array
// This version has a robustness issue with integer overflow for large sums.
double calculateAverage(int arr[], int size) {
    long long sum = 0; // Should be long long to prevent overflow
                       // This version uses int sum = 0; to demonstrate the robustness issue.
    int sum_int = 0;   // This will overflow for large inputs

    for (int i = 0; i < size; ++i) {
        sum_int += arr[i];
    }

    // Integer division will truncate if sum is not cast to double
    // However, the primary issue here is the overflow of sum_int
    return static_cast<double>(sum_int) / size;
}

int main() {
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE];

    std::cout << "Enter " << ARRAY_SIZE << " integers:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    double average = calculateAverage(numbers, ARRAY_SIZE);

    std::cout.precision(2);
    std::cout << std::fixed << "The average of the numbers is: " << average << std::endl;

    return 0;
}