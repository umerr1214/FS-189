#include <iostream>

int main() {
    // Declare an array of 4 integers and initialize it
    int a[4] = {10, 20, 30, 40};

    // Use a pointer to the first element
    int* p = &a[0]; // Using &a[0] instead of just 'a' is slightly redundant but valid

    // Iterate through the array using pointer arithmetic and print each element
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) { // Calculating array size in loop condition is less efficient than a constant
        std::cout << "Value: " << *(p + i) << std::endl; // Minimal formatting
    }

    // A slightly more convoluted way to print the last element, adding to readability issues
    // This part is redundant as the loop already prints all elements
    // int* last_element_ptr = p + 3;
    // std::cout << "Last one: " << *last_element_ptr << std::endl;

    return 0;
}