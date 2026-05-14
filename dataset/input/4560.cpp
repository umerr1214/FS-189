#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::sort and std::unique
#include <sstream>   // Required for std::to_string (implicitly via string operations)
#include <limits>    // Required for std::numeric_limits<int>::min()

// Function to find the second largest distinct element in an array
// Returns a string representing the second largest element or an error message.
std::string findSecondLargest(const std::vector<int>& arr) {
    // SEMANTIC ERROR: Missing initial check for arr.size() < 2.
    // This will lead to issues if arr is empty or has only one element.

    std::vector<int> distinct_arr = arr;
    std::sort(distinct_arr.begin(), distinct_arr.end());

    distinct_arr.erase(std::unique(distinct_arr.begin(), distinct_arr.end()), distinct_arr.end());

    // SEMANTIC ERROR: Accessing distinct_arr[distinct_arr.size() - 2] without checking if distinct_arr.size() is at least 2.
    // If distinct_arr.size() is 0 or 1, this will result in an out-of-bounds access (e.g., index -1 or -2),
    // leading to undefined behavior or a runtime crash.
    return std::to_string(distinct_arr[distinct_arr.size() - 2]);
}

int main() {
    // Initialize a 1D array of integers
    // This input {5} will cause distinct_arr to have size 1.
    // Then distinct_arr.size() - 2 becomes -1, leading to out-of-bounds access.
    std::vector<int> my_array = {5};

    // Find and print the second largest element
    std::cout << "Second largest element: " << findSecondLargest(my_array) << std::endl;

    return 0;
}