#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

// Function template to calculate the average of an array of numeric types
template <typename T>
T calculate_average(const T arr[], int size) {
    T sum = 0; // sum is of type T
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    // SEMANTIC ERROR: The function is declared to return type 'T'.
    // However, it attempts to return a 'double' value by explicitly casting 'sum' to 'double'
    // before division. If 'T' is, for example, 'int', this constitutes an invalid
    // implicit conversion from 'double' to 'int' in the return statement, which
    // is a semantic error (loss of precision/type mismatch).
    return static_cast<double>(sum) / size;
}

int main() {
    // Test case 1: int array
    int int_arr[] = {1, 2, 3, 4, 5};
    int int_size = sizeof(int_arr) / sizeof(int_arr[0]);
    std::cout << "Average of int_arr: " << std::fixed << std::setprecision(2) << calculate_average(int_arr, int_size) << std::endl;

    // Test case 2: double array
    double double_arr[] = {10.0, 20.5, 30.0, 40.5};
    int double_size = sizeof(double_arr) / sizeof(double_arr[0]);
    std::cout << "Average of double_arr: " << std::fixed << std::setprecision(2) << calculate_average(double_arr, double_size) << std::endl;

    // Test case 3: another int array with non-integer average
    int int_arr_2[] = {1, 2, 4}; // Correct average should be 7/3 = 2.33
    int int_size_2 = sizeof(int_arr_2) / sizeof(int_arr_2[0]);
    std::cout << "Average of int_arr_2: " << std::fixed << std::setprecision(2) << calculate_average(int_arr_2, int_size_2) << std::endl;
    
    // Test case 4: float array
    float float_arr[] = {1.5f, 2.5f, 3.5f};
    int float_size = sizeof(float_arr) / sizeof(float_arr[0]);
    std::cout << "Average of float_arr: " << std::fixed << std::setprecision(2) << calculate_average(float_arr, float_size) << std::endl;

    return 0;
}