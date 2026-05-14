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

    // SEMANTIC ERROR: The loop condition allows dereferencing an out-of-bounds pointer.
    // 'arr + size' points one past the last valid element.
    // Using '<=' with 'arr + size' means the loop will attempt to dereference '*(arr + size)',
    // which is beyond the allocated memory for the array. This leads to undefined behavior,
    // typically a segmentation fault.
    int* endPtr = arr + size; // Points one past the last element
    while (currentPtr <= endPtr) { // This condition is incorrect; should be 'currentPtr < endPtr'
        sum += *currentPtr; // Dereferences arr[size] in the last iteration
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