#include <iostream>

// Function with a logical error: it swaps the pointer addresses, not the values they point to.
void swapValues(int* ptr1, int* ptr2) {
    int* temp = ptr1; // This stores the address of ptr1
    ptr1 = ptr2;      // ptr1 now points to what ptr2 points to (locally)
    ptr2 = temp;      // ptr2 now points to what ptr1 originally pointed to (locally)
    // The values at the original memory locations *ptr1 and *ptr2 remain unchanged.
}

int main() {
    int a = 10;
    int b = 20;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swapValues(&a, &b); // Calls the function with the logical error
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    return 0;
}