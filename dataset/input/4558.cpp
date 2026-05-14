#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::sort and std::unique
#include <sstream>   // Required for std::to_string (implicitly via string operations)
#include <limits>    // Required for std::numeric_limits<int>::min()

// Function to find the second largest distinct element in an array
// Returns a string representing the second largest element or an error message.
std::string findSecondLargest(const std::vector<int>& arr) {
    if (arr.size() < 2) {
        return "No second largest element";
    }

    // Create a copy to sort and find unique elements
    std::vector<int> distinct_arr = arr;
    std::sort(distinct_arr.begin(), distinct_arr.end());

    // Remove duplicate elements
    distinct_arr.erase(std::unique(distinct_arr.begin(), distinct_arr.end()), distinct_arr.end());

    // After removing duplicates, if there are less than 2 elements,
    // then a distinct second largest doesn't exist.
    if (distinct_arr.size() < 2) {
        return "No second largest element";
    }

    // The second largest distinct element will be at the second to last position
    // after sorting and removing duplicates.
    return std::to_string(distinct_arr[distinct_arr.size() - 2]);
}

int main() {
    // Initialize a 1D array of integers
    std::vector<int> my_array = {10, 5, 20, 15, 25};

    // Find and print the second largest element
    std::cout << "Second largest element: " << findSecondLargest(my_array) std::endl; // SYNTAX ERROR: Missing '<<' operator

    return 0;
}