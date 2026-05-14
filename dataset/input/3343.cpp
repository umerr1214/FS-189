#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

// Function with a robustness issue: it does not handle the case where 'size' is 0,
// leading to a division-by-zero runtime error if an empty array is passed.
double calculate_average(const int arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    // If 'size' is 0, 'sum' will be 0.0.
    // The division 'sum / static_cast<double>(size)' will result in 0.0 / 0,
    // which causes a floating-point exception (division by zero) at runtime.
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

    // Pass nullptr for arr if size is 0, as the function should not dereference it
    // if size is 0 and the loop won't run. The issue is purely the division.
    const int* arr_ptr = arr_vec.empty() ? nullptr : arr_vec.data();

    double result = calculate_average(arr_ptr, size);

    std::cout << std::fixed << std::setprecision(6) << result << std::endl;

    return 0;
}