#include <iostream>

int main() {
    // Declare variables for sizes
    int s1, s2;

    // Get size of first array
    std::cout << "Enter the size of the first array: ";
    std::cin >> s1;

    // Allocate memory for first array
    int* arrA = new int[s1];

    // Read elements for first array
    std::cout << "Enter " << s1 << " elements for the first array:" << std::endl;
    for (int i = 0; i < s1; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arrA[i];
    }

    // Get size of second array
    std::cout << "Enter the size of the second array: ";
    std::cin >> s2;

    // Allocate memory for second array
    int* arrB = new int[s2];

    // Read elements for second array
    std::cout << "Enter " << s2 << " elements for the second array:" << std::endl;
    for (int i = 0; i < s2; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arrB[i];
    }

    // Calculate total size for concatenated array
    int t_sz = s1 + s2;

    // Allocate memory for concatenated array
    int* resArr = new int[t_sz];

    // Manually copy elements from arrA to resArr
    for (int i = 0; i < s1; ++i) {
        resArr[i] = arrA[i];
    }

    // Manually copy elements from arrB to resArr, starting after arrA's elements
    for (int i = 0; i < s2; ++i) {
        resArr[s1 + i] = arrB[i];
    }

    // Print the concatenated array
    std::cout << "Concatenated array: ";
    for (int i = 0; i < t_sz; ++i) {
        std::cout << resArr[i] << (i == t_sz - 1 ? "" : " ");
    }
    std::cout << std::endl;

    // Free dynamically allocated memory
    delete[] arrA;
    delete[] arrB;
    delete[] resArr;

    return 0;
}