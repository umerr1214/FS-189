#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // For std::numeric_limits

int main() {
    std::vector<int> arr(5);
    std::cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    if (arr.empty()) {
        std::cout << "Array is empty, no second largest element." << std::endl;
        return 0;
    }

    int largest = std::numeric_limits<int>::min();
    for (int x : arr) {
        if (x > largest) {
            largest = x;
        }
    }

    int secondLargest = std::numeric_limits<int>::min();
    // Logical error: This logic finds the largest element *strictly smaller* than 'largest'.
    // It fails if the second largest value is equal to the largest value (e.g., {5,5,3,2,1} -> finds 3 instead of 5).
    // It also fails if all elements are the same (e.g., {7,7,7,7,7} -> finds INT_MIN instead of 7).
    for (int x : arr) {
        if (x > secondLargest && x < largest) { // The critical flaw: x < largest
            secondLargest = x;
        }
    }

    if (secondLargest == std::numeric_limits<int>::min()) {
        // This message is misleading for inputs like {5,5,5,5,5} where the second largest is 5.
        std::cout << "There is no second distinct largest element or array has less than two distinct elements." << std::endl;
    } else {
        std::cout << "The second largest element is: " << secondLargest << std::endl;
    }

    return 0;
}