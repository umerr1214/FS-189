#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // For std::numeric_limits

int main() {
    std::vector<int> arr(5);
    std::cout << "Enter 5 integers: " // Missing semicolon here
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    // Logic to find second largest (even if it won't compile due to syntax error)
    // This part is conceptually correct for finding second largest among distinct elements.
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