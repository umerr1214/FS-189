#include <iostream>

void swap_integers(int* a, int* b) {
    // Readability / Efficiency Issue: Uses bitwise XOR swap.
    // While technically correct for integers, it is generally less readable
    // and less intuitive than using a temporary variable for many developers.
    // It also offers no significant performance benefits on modern CPUs and
    // can be confusing if not understood well.
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int x = 15;
    int y = 25;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap_integers(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    
    int p = 5;
    int q = 5;
    std::cout << "\nBefore swap (p,q same): p = " << p << ", q = " << q << std::endl;
    swap_integers(&p, &q);
    std::cout << "After swap (p,q same): p = " << p << ", q = " << q << std::endl;

    return 0;
}