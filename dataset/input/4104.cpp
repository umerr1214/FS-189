#include <iostream>
#include <numeric>
#include <iomanip>

// Function to calculate the average of elements in an array
double calculateAverage(int arr[], int size) {
    if (size <= 0) {
        return 0.0;
    }
    long long sum = 0;
    // SEMANTIC ERROR: Loop condition 'i <= size' causes an out-of-bounds access.
    // It should be 'i < size'.
    for (int i = 0; i <= size; ++i) { // This loop iterates one time too many
        sum += arr[i]; // When i == size, this accesses arr[size], which is out of bounds
    }
    return static_cast<double>(sum) / size;
}

int main() {
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE];

    std::cout << "Enter " << ARRAY_SIZE << " integers:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter number " << (i + 1) << ": ";
        std::cin >> numbers[i];
    }

    double average = calculateAverage(numbers, ARRAY_SIZE);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The average of the elements is: " << average << std::endl;

    return 0;
}