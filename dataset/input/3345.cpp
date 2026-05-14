#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision
#include <numeric> // For std::accumulate (though a manual loop is used here for clarity)

// Correct, robust, and efficient function to calculate the average of elements in an array.
double calculate_average(const int arr[], int size) {
    if (size <= 0) { // Robustly handles empty or non-positive array sizes.
                     // The average of an empty set is conventionally 0.0.
        return 0.0;
    }

    double sum = 0.0;
    // Efficiently iterate through the array once.
    // Using a 'double' for 'sum' prevents potential integer overflow for large sums
    // and ensures floating-point arithmetic for the average.
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    
    // Perform division using 'double' to get an accurate floating-point average.
    return sum / static_cast<double>(size);
}

// Driver code to read input, call the function, and print the result
int main() {
    std::string line;
    std::getline(std::cin, line);
    int size = std::stoi(line);

    std::vector<int> arr_vec;
    if (size > 0) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int val;
        for (int i = 0; i < size; ++i) {
            ss >> val;
            arr_vec.push_back(val);
        }
    }

    const int* arr_ptr = arr_vec.empty() ? nullptr : arr_vec.data();

    double result = calculate_average(arr_ptr, size);

    std::cout << std::fixed << std::setprecision(6) << result << std::endl;

    return 0;
}