#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

// Function to calculate the average of elements in an array
// Uses long long for sum to prevent overflow and returns double for precision.
double calculateAverage(int arr[], int size) {
    if (size <= 0) {
        return 0.0; // Handle empty or invalid array size gracefully
    }

    long long sum = 0; // Use long long to prevent integer overflow for large sums

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    // Cast sum to double before division to ensure floating-point division
    return static_cast<double>(sum) / size;
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

    // Display the average with two decimal places
    std::cout << std::fixed << std::setprecision(2) << "The average of the numbers is: " << average << std::endl;

    return 0;
}