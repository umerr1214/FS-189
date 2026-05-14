#include <iostream>

// Syntax Error: Missing closing angle bracket in template parameter list
template <typename T
T arraySum(const T arr[], int size) {
    T sum = T(); // Initialize with default constructor (0 for numeric types)
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // This program contains a syntax error in the 'arraySum' template definition
    // and will not compile. The following lines are commented out as they
    // would immediately result in a compilation failure.

    // int intArray[] = {1, 2, 3, 4, 5};
    // int intSize = sizeof(intArray) / sizeof(intArray[0]);
    // std::cout << "Sum of int array: " << arraySum(intArray, intSize) << std::endl;

    // double doubleArray[] = {1.1, 2.2, 3.3};
    // int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    // std::cout << "Sum of double array: " << arraySum(doubleArray, doubleSize) << std::endl;

    std::cout << "This program contains a syntax error and is designed to fail compilation." << std::endl;
    std::cout << "The 'arraySum' function template is missing a closing angle bracket in its definition." << std::endl;

    return 0;
}