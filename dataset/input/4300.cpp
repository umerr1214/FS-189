#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

// Function template to calculate the average of an array of numeric types
template <typename T>
T calculate_average(const T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    // This line below implicitly casts sum/size to T.
    // For integer types, this would result in integer division.
    // For this syntax error example, the logic is otherwise correct.
    return sum / size;
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
    int int_arr_2[] = {1, 2, 4}; // Average should be 7/3 = 2.33
    int int_size_2 = sizeof(int_arr_2) / sizeof(int_arr_2[0]);
    std::cout << "Average of int_arr_2: " << std::fixed << std::setprecision(2) << calculate_average(int_arr_2, int_size_2) << std::endl;
    
    // Test case 4: float array
    float float_arr[] = {1.5f, 2.5f, 3.5f};
    int float_size = sizeof(float_arr) / sizeof(float_arr[0]);
    std::cout << "Average of float_arr: " << std::fixed << std::setprecision(2) << calculate_average(float_arr, float_size) << std::endl;

    // MISSING CLOSING BRACE FOR main() - SYNTAX ERROR
// }