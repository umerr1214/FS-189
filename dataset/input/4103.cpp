#include <iostream>
#include <numeric>
#include <iomanip>

// Function to calculate the average of elements in an array
// LOGICAL ERROR: Returns int, causing integer division truncation.
int calculateAverage(int arr[], int size) { // Should return double for accurate average
    if (size <= 0) {
        return 0; // Returns 0 for invalid size, but problem implies valid size
    }
    long long sum = 0; // Use long long to prevent overflow for sum
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    // Logical Error: Integer division truncates the decimal part
    return sum / size; // This will return an integer, not a double average
}

int main() {
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE];

    std::cout << "Enter " << ARRAY_SIZE << " integers:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter number " << (i + 1) << ": ";
        std::cin >> numbers[i];
    }

    // The return type of calculateAverage is int, so 'average' will receive a truncated integer value.
    double average = calculateAverage(numbers, ARRAY_SIZE);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The average of the elements is: " << average << std::endl;

    return 0;
}