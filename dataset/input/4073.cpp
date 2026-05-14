#include <iostream>

int main() {
    int height;
    std::cout << "Enter height: ";
    std::cin >> height;
    
    // Logical error: Prints an inverted triangle instead of a right-angled triangle ascending
    for (int i = height; i >= 1; --i) { // Outer loop iterates from height down to 1
        for (int j = 1; j <= i; ++j) { // Inner loop prints 'i' stars
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    return 0;
}