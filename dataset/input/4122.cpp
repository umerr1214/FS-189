#include <iostream>

int main() {
    // Declare variables
    int int_var = 10;
    float float_var = 20.5f;
    char char_var = 'A';

    // Declare pointers
    int* int_ptr;
    float* float_ptr;
    char* char_ptr; // Declared but not assigned an address initially

    // Assign addresses
    int_ptr = &int_var;
    float_ptr = &float_var;
    char_ptr = nullptr; // SEMANTIC ERROR: Assigning nullptr to char_ptr, which will be dereferenced later

    // Print memory addresses
    std::cout << "Address of int_var (stored in int_ptr): " << int_ptr << std::endl;
    std::cout << "Address of float_var (stored in float_ptr): " << float_ptr << std::endl;
    std::cout << "Address of char_var (stored in char_ptr): " << static_cast<void*>(char_ptr) << std::endl;

    // Print values pointed to by dereference operator
    std::cout << "Value pointed to by int_ptr: " << *int_ptr << std::endl;
    std::cout << "Value pointed to by float_ptr: " << *float_ptr << std::endl;
    std::cout << "Value pointed to by char_ptr: " << *char_ptr << std::endl; // SEMANTIC ERROR: Dereferencing a nullptr

    return 0;
}