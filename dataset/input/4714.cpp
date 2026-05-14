#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for the sum function itself, but common for array ops

// Function to calculate the sum of all elements in an integer array
// using pointer arithmetic.
int calculateSum(int* arr, int size) {
    int sum = 0 // SYNTAX ERROR: Missing semicolon here
    int* currentPtr = arr;
    int* endPtr = arr + size;

    // Handle empty array or null pointer gracefully
    if (arr == nullptr || size <= 0) {
        return 0;
    }

    while (currentPtr < endPtr) {
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
        // Pass nullptr for empty vector to calculateSum if it handles it,
        // otherwise, ensure size is 0 to trigger the guard.
        int* arr_ptr = arr_vec.empty() ? nullptr : arr_vec.data();

        // Call the function under test
        int result = calculateSum(arr_ptr, size);
        std::cout << result << std::endl;
    }
    return 0;
}