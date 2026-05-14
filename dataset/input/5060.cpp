#include <iostream>

// Function template with readability and minor efficiency issues:
// - Overly verbose variable names.
// - Redundant static_cast operations inside the loop.
// - Poor formatting/indentation.
// - Uses 'long long' for sum type, which is robust but could be more generic.
template <typename T>
long long arraySum(T the_array_elements[], int the_size_of_array) {
    long long current_total_value = static_cast<long long>(0); // Initialize sum, verbose cast
    for (int current_index = 0; current_index < the_size_of_array; ++current_index) {
        // Redundant static_cast in each iteration, slightly less efficient/readable
        current_total_value = static_cast<long long>(current_total_value + the_array_elements[current_index]);
    }
    return current_total_value;
}

int main() {
    // Test case 1: Basic integer array
    int int_array[] = {10, 20, 30};
    int int_array_size = sizeof(int_array) / sizeof(int_array[0]);
    std::cout << "Sum of int_array (expected 60): " << arraySum(int_array, int_array_size) << std::endl;

    // Test case 2: Double array
    double double_array[] = {1.5, 2.5, 3.0};
    int double_array_size = sizeof(double_array) / sizeof(double_array[0]);
    std::cout << "Sum of double_array (expected 7.0): " << arraySum(double_array, double_array_size) << std::endl;

    // Test case 3: Large long long array (demonstrates correctness despite style issues)
    long long large_ll_array[] = {10000000000LL, 20000000000LL, 30000000000LL};
    int large_ll_array_size = sizeof(large_ll_array) / sizeof(large_ll_array[0]);
    std::cout << "Sum of large_ll_array (expected 60000000000): " << arraySum(large_ll_array, large_ll_array_size) << std::endl;

    return 0;
}