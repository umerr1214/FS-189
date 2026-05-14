#include <iostream>

int main() {
    // Declare float and char variables and their pointers
    float float_var = 3.14f;
    char char_var = 'C';

    float* float_ptr = &float_var;
    char* char_ptr = &char_var;

    // Robustness Issue: Create a dangling pointer
    // Declare an int pointer
    int* int_ptr;

    { // A new scope
        int temp_int_var = 42; // Local variable
        int_ptr = &temp_int_var; // int_ptr points to temp_int_var
        std::cout << "Inside scope: temp_int_var value = " << temp_int_var << ", address = " << int_ptr << std::endl;
    } // temp_int_var goes out of scope here, int_ptr becomes a dangling pointer

    // Attempt to dereference the dangling pointer
    // This leads to undefined behavior, as the memory int_ptr points to is no longer valid.
    std::cout << "Address of int_variable (dangling): " << int_ptr << std::endl;
    std::cout << "Value pointed by int_pointer (dangling - undefined behavior): " << *int_ptr << std::endl; // Potential crash or garbage value

    // Print for float
    std::cout << "Address of float_variable: " << float_ptr << std::endl;
    std::cout << "Value pointed by float_pointer: " << *float_ptr << std::endl;

    // Print for char
    std::cout << "Address of char_variable: " << static_cast<void*>(char_ptr) << std::endl; // Cast char* to void* to print address correctly
    std::cout << "Value pointed by char_pointer: " << *char_ptr << std::endl;

    return 0;
}