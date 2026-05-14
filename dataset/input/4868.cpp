#include <iostream> // Required for std::cout, std::endl

// Readability / Efficiency Issue:
// - Inefficiently flushes the output buffer on every iteration using `std::cout.flush()`.
// - Uses overly verbose, unclear, and inconsistent variable names.
// - Poor and inconsistent code formatting/indentation.
// - Lacks comments to explain the function or any non-obvious logic.
void printArrayElements(int* ptr_to_int_array_elements, int num_elements_in_array) {
    for ( int index_iterator_for_array = 0 ; index_iterator_for_array < num_elements_in_array ; ++index_iterator_for_array )
    {
        std::cout << ptr_to_int_array_elements[index_iterator_for_array] << " ";
        std::cout.flush(); // Inefficient: flushes the buffer on every single iteration
    }
    std::cout << std::endl; // Finally adds a newline and flushes again
}

int main() {
    // Demonstrate with a valid array
    int my_int_data_array[] = {11, 22, 33, 44, 55};
    int total_count_of_elements = sizeof(my_int_data_array) / sizeof(my_int_data_array[0]);
    std::cout << "Test Case 1 (Valid Array):\n";
    printArrayElements(my_int_data_array, total_count_of_elements); // Expected: 11 22 33 44 55 \n

    // Demonstrate with an empty array
    int empty_array_for_test[] = {};
    int zero_elements_count = 0;
    std::cout << "Test Case 2 (Empty Array):\n";
    printArrayElements(empty_array_for_test, zero_elements_count); // Expected: \n

    return 0;
}