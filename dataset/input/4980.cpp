#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // For std::numeric_limits

int main() {
    // Array of size 5, valid indices are 0 to 4.
    std::vector<int> arr(5);
    std::cout << "Enter 5 integers: ";
    // Semantic error: Loop goes from 0 to 5 (inclusive), attempting to access arr[5] which is out-of-bounds.
    for (int i = 0; i <= 5; ++i) { // Should be i < 5
        std::cin >> arr[i]; // Potential runtime error/undefined behavior when i is 5
    }

    // The rest of the logic is intended to be correct, but the program's behavior is undefined
    // due to the preceding out-of-bounds write.
    int largest = std::numeric_limits<int>::min();
    int secondLargest = std::numeric_limits<int>::min();

    for (int x : arr) {
        if (x > largest) {
            secondLargest = largest;
            largest = x;
        } else if (x > secondLargest && x != largest) {
            secondLargest = x;
        }
    }

    if (secondLargest == std::numeric_limits<int>::min()) {
        std::cout << "There is no second largest element (e.g., all elements are same or less than 2 distinct elements)." << std::endl;
    } else {
        std::cout << "The second largest element is: " << secondLargest << std::endl;
    }

    return 0;
}