#include <iostream> // Include necessary header for input/output operations.

// Main function where the program execution begins.
int main() { // Start of the main function block.

    // Declare an integer variable.
    // It's named 'x' for brevity, potentially making it less descriptive.
    int x = 10; // Initialize the integer variable 'x' with the value 10.

    // Declare a pointer to an integer.
    // It's named 'p' for brevity, potentially making it less descriptive.
    int* p; // Declare a pointer 'p' of type int*.

    // Make the pointer 'p' point to the memory address of 'x'.
    // This is done using the address-of operator '&'.
    p = &x; // Assign the address of 'x' to the pointer 'p'.

    // Modify the value of the integer variable 'x' using only the pointer 'p'.
    // The dereference operator '*' is used to access the value at the address 'p' points to.
    // The value is changed from 10 to 20.
    *p = 20; // Dereference 'p' and assign the new value 20 to 'x'.

    // Print the new value of the integer variable 'x'.
    // Use std::cout for output to the console.
    std::cout << "The new value of the integer variable is: " << x << std::endl; // Output the modified value.

    // Print the memory address of the integer variable 'x'.
    // The pointer 'p' holds this memory address.
    std::cout << "The memory address of the integer variable is: " << p << std::endl; // Output the memory address.

    // Return 0 to indicate successful program execution.
    return 0; // End of the main function block.
}