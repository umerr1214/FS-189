#include <iostream>

// C++ function template to find the maximum of two values
template <typename T>
T findMax(T val1, T val2) {
    return (val1 > val2) ? val1 : val2;
}

int main() {
    // Test with int (works correctly)
    int int_val1 = 5;
    int int_val2 = 10;
    int int_result = findMax(int_val1, int_val2);
    std::cout << "Max of " << int_val1 << " and " << int_val2 << " is: " << int_result << std::endl;

    // Test with double (works correctly)
    double double_val1 = 3.5;
    double double_val2 = 7.2;
    double double_result = findMax(double_val1, double_val2);
    std::cout << "Max of " << double_val1 << " and " << double_val2 << " is: " << double_result << std::endl;

    // Test with pointer types (Semantic Error: compares addresses, not pointed-to values)
    int value_a = 50;
    int value_b = 20; // value_a is numerically greater than value_b

    int* ptr_a = &value_a;
    int* ptr_b = &value_b;

    // findMax will compare the memory addresses of ptr_a and ptr_b, not the values they point to.
    // Assuming typical stack allocation where 'value_a' (declared first) has a lower address than 'value_b'.
    // So, &value_a < &value_b. Thus, findMax(&value_a, &value_b) will return &value_b.
    int* max_ptr_result = findMax(ptr_a, ptr_b);
    
    std::cout << "Max of values pointed to by " << *ptr_a << " and " << *ptr_b 
              << " (comparing addresses) is: " << *max_ptr_result << std::endl; // Actual: 20 (value_b), Expected value max: 50 (value_a)

    return 0;
}