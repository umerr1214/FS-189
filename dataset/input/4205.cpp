#include <iostream>

// Function to swap the values pointed to by two integer pointers
void swap_integers(int* a, int* b)
{
    // LOGICAL ERROR: This logic assigns the value of *b to *a,
    // and then assigns the (now modified) value of *a (which is *b's original value) to *b.
    // Effectively, both *a and *b will end up with the original value of *b.
    *a = *b;
    *b = *a;
}

int main()
{
    int val1 = 100;
    int val2 = 200;

    std::cout << "Before swap:" << std::endl;
    std::cout << "val1 = " << val1 << ", val2 = " << val2 << std::endl;

    swap_integers(&val1, &val2);

    std::cout << "After swap:" << std::endl;
    std::cout << "val1 = " << val1 << ", val2 = " << val2 << std::endl;

    return 0;
}