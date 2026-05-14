#include <iostream>

void swap_integers(int* a, int* b) {
    // Correct, robust, and readable implementation.
    // It includes nullptr checks for robustness, preventing crashes if invalid pointers are passed.
    if (a == nullptr || b == nullptr) {
        std::cerr << "Warning: `swap_integers` received a nullptr argument. No swap performed." << std::endl;
        return; // Gracefully handle invalid input
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 100;
    int y = 200;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap_integers(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    int p = 77;
    int q = 77;
    std::cout << "\nBefore swap (p,q same): p = " << p << ", q = " << q << std::endl;
    swap_integers(&p, &q);
    std::cout << "After swap (p,q same): p = " << p << ", q = " << q << std::endl;

    // Demonstrate robust handling of nullptr
    int z = 300;
    int* ptr_null = nullptr;
    std::cout << "\nDemonstrating nullptr handling:" << std::endl;
    std::cout << "Before swap (z, nullptr): z = " << z << std::endl;
    swap_integers(&z, ptr_null); // Should print warning and not modify z or crash
    std::cout << "After swap (z, nullptr): z = " << z << std::endl;

    return 0;
}