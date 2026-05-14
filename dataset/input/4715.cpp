#include <iostream>
#include <vector>
#include <numeric>
#include <sstream>

// Function to calculate the sum of all elements in an integer array
// using pointer arithmetic.
int calculateSum(int* arr, int size) {
    int sum = 0;
    int* currentPtr = arr;

    // Handle empty array or null pointer gracefully
    if (arr == nullptr || size <= 0) {
        return 0;
    }

    // LOGICAL ERROR: The loop condition is incorrect, causing it to miss the last element.
    // It should be 'currentPtr < arr + size' to include all 'size' elements.
    // By using 'arr + size - 1' as the upper bound in a '<' comparison,
    // it effectively iterates 'size - 1' times for arrays of size > 0.
    int* endPtrOneBeforeLast = arr + size - 1;
    while (currentPtr < endPtrOneBeforeLast) {
        sum += *currentPtr;
        currentPtr++;
    }
    return sum;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int val;
        std::vector<int> arr_vec;
        while (ss >> val) {
            arr_vec.push_back(val);
        }

        int size = arr_vec.size();
        int* arr_ptr = arr_vec.empty() ? nullptr : arr_vec.data();

        int result = calculateSum(arr_ptr, size);
        std::cout << result << std::endl;
    }
    return 0;
}