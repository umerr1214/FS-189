#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision
#include <numeric> // Not strictly needed for this implementation, but often included for sums

// Function with readability and efficiency issues: it unnecessarily copies the array.
double calculate_average(const int arr[], int size) {
    if (size <= 0) { // Handles empty array gracefully
        return 0.0;
    }

    // Efficiency issue: This block unnecessarily copies all elements from the
    // input C-style array into a new std::vector. This involves dynamic memory
    // allocation and an extra loop, which adds overhead and is inefficient
    // for simply calculating the average of an already existing array.
    std::vector<int> temp_elements;
    temp_elements.reserve(size); // A minor optimization, but the copy is still unnecessary.
    for (int i = 0; i < size; ++i) {
        temp_elements.push_back(arr[i]);
    }

    double total_sum = 0.0;
    // Readability issue: Iterating over the copied vector ('temp_elements')
    // instead of the original array ('arr') adds an unnecessary layer of
    // indirection without providing any functional benefit for this task.
    for (int val : temp_elements) {
        total_sum += val;
    }
    
    return total_sum / static_cast<double>(size);
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