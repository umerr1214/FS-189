#include <iostream>

// Function to swap the values pointed to by two integer pointers
void swap_integers(int* a, int* b)
{
    // SEMANTIC ERROR: Using 'char' for temporary storage can lead to data loss
    // if the integer values exceed the range of a char (-128 to 127 for signed char).
    // This compiles but produces incorrect results for large integer values.
    char temp = *a; // Potential data truncation here
    *a = *b;
    *b = temp; // 'temp' might hold a truncated value
}

int main()
{
    int val1 = 200; // Value exceeds signed char max (127)
    int val2 = 10;

    std::cout << "Before swap:" << std::endl;
    std::cout << "val1 = " << val1 << ", val2 = " << val2 << std::endl;

    swap_integers(&val1, &val2);

    std::cout << "After swap:" << std::endl;
    std::cout << "val1 = " << val1 << ", val2 = " << val2 << std::endl;

    int val3 = -150; // Value exceeds signed char min (-128)
    int val4 = 50;

    std::cout << "\nBefore swap (second test):" << std::endl;
    std::cout << "val3 = " << val3 << ", val4 = " << val4 << std::endl;

    swap_integers(&val3, &val4);

    std::cout << "After swap (second test):" << std::endl;
    std::cout << "val3 = " << val3 << ", val4 = " << val4 << std::endl;

    return 0;
}