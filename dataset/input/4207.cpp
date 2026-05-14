#include <iostream>

void swap_integers(int* a, int* b) {
    // Robustness issue: This implementation does not check if 'a' or 'b' are nullptr.
    // Dereferencing a nullptr would lead to undefined behavior or a crash.
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap_integers(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    int p = 5;
    int q = 5;
    std::cout << "\nBefore swap (p,q same): p = " << p << ", q = " << q << std::endl;
    swap_integers(&p, &q);
    std::cout << "After swap (p,q same): p = " << p << ", q = " << q << std::endl;
    
    // Note: The main function here uses valid pointers to avoid crashing.
    // The robustness issue lies in the swap_integers function itself,
    // which would fail if called with a nullptr.
    // Example of what would cause a crash if uncommented:
    // int* ptr_null = nullptr;
    // swap_integers(&x, ptr_null); 

    return 0;
}