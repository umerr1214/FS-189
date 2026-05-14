#include <iostream>

// An unnecessarily verbose and inefficient way to increment a value by 10
void increment_by_one_ten_times(int* target_ptr) {
    // A basic null check, but the primary issue is the inefficiency of the loop
    if (target_ptr == nullptr) {
        return;
    }
    for (int i = 0; i < 10; ++i) {
        (*target_ptr)++; // Increment by 1, ten times in a loop
    }
}

int main() {
    // Define two integer variables
    int val1 = 10;
    int val2 = 20;

    // Store original values separately for printing later.
    // While functionally correct, for this simple case, printing `val1` and `val2`
    // before modification would be more direct and slightly more efficient.
    int original_val1 = val1;
    int original_val2 = val2;

    // Define pointers to these variables
    int* ptr_to_val1 = &val1;
    int* ptr_to_val2 = &val2;

    // Modify the values using the inefficient helper function
    increment_by_one_ten_times(ptr_to_val1);
    increment_by_one_ten_times(ptr_to_val2);

    // Print original and modified values
    std::cout << "Original var1: " << original_val1 << ", var2: " << original_val2 << std::endl;
    std::cout << "Modified var1: " << val1 << ", var2: " << val2 << std::endl;

    return 0;
}