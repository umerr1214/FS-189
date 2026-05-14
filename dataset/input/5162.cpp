#include <iostream>

int main() {
    int hgt; // Poor variable name: 'hgt' instead of 'height'
    std::cout << "Enter the height of the triangle: ";
    std::cin >> hgt;

    // Basic check to prevent infinite loop/crash for non-positive,
    // but still not robust input validation.
    if (hgt <= 0) {
        return 0;
    }

    for (int i_idx = 1; i_idx <= hgt; ++i_idx) { // Obscure variable name: 'i_idx'
        for (int j_idx = 1; j_idx <= i_idx; ++j_idx) { // Obscure variable name: 'j_idx'
            std::cout << "*";
        }
        std::cout << std::endl; // Inefficient: std::endl flushes the buffer on each line
    }

    return 0;
}