#include <iostream>

int main() {
    // Declare an int variable and its pointer
    int integer_variable = 100;
    int* integer_pointer = &integer_variable;

    // Declare a float variable and its pointer
    float float_variable = 50.75f;
    float* float_pointer = &float_variable;

    // Declare a char variable and its pointer
    char char_variable = 'X';
    char* char_pointer = &char_variable;

    // Print the memory address stored in each pointer and the value pointed to by each pointer
    std::cout << "--- Integer Variable ---" << '\n';
    std::cout << "Address of integer_variable: " << integer_pointer << '\n';
    std::cout << "Value pointed by integer_pointer: " << *integer_pointer << '\n';
    std::cout << '\n';

    std::cout << "--- Float Variable ---" << '\n';
    std::cout << "Address of float_variable: " << float_pointer << '\n';
    std::cout << "Value pointed by float_pointer: " << *float_pointer << '\n';
    std::cout << '\n';

    std::cout << "--- Character Variable ---" << '\n';
    // When printing char* directly, it's often interpreted as a C-style string.
    // Casting to void* ensures the actual memory address is printed.
    std::cout << "Address of char_variable: " << static_cast<void*>(char_pointer) << '\n';
    std::cout << "Value pointed by char_pointer: " << *char_pointer << '\n';

    return 0;
}