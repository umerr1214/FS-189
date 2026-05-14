#include <iostream>

// Function to swap the values pointed to by two integer pointers
void swap_integers(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp
} // SYNTAX ERROR: Missing semicolon here

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