#include <iostream>

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // Array declaration
    int size = sizeof(arr) / sizeof(arr[0]) // Syntax Error: Missing semicolon here
    int sum = 0;
    int* ptr = arr; // Pointer to the first element

    for (int i = 0; i < size; ++i) {
        sum += *ptr; // Add the value pointed to by ptr
        ptr++;       // Move to the next element
    }

    std::cout << "Sum of array elements: " << sum << std::endl;

    return 0;
}