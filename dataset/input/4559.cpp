#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <limits> // Required for std::numeric_limits<int>::min()

// Function to find the second largest distinct element in an array
// Returns a string representing the second largest element or an error message.
std::string findSecondLargest(const std::vector<int>& arr) {
    if (arr.empty()) {
        return "No second largest element";
    }

    int largest = std::numeric_limits<int>::min();
    int secondLargest = std::numeric_limits<int>::min();

    for (int x : arr) {
        if (x > largest) {
            secondLargest = largest; // The old largest becomes the new second largest
            largest = x;
        } else if (x > secondLargest) { // LOGICAL ERROR: This condition allows 'x' to be equal to 'largest'
                                        // if 'largest' is a duplicate, causing 'secondLargest' to incorrectly
                                        // become equal to 'largest'.
            secondLargest = x;
        }
    }

    // Check if a valid distinct second largest was found.
    // If largest == secondLargest, it means either all elements were the same,
    // or a duplicate of the largest element was incorrectly assigned to secondLargest.
    if (secondLargest == std::numeric_limits<int>::min() || largest == secondLargest) {
        return "No second largest element";
    }

    return std::to_string(secondLargest);
}

int main() {
    // Initialize a 1D array of integers
    std::vector<int> my_array = {20, 10, 20}; // This input will highlight the logical error: expected 10, actual "No second largest"

    // Find and print the second largest element
    std::cout << "Second largest element: " << findSecondLargest(my_array) << std::endl;

    return 0;
}