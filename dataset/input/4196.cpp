#include <iostream>

int main() {
    std::cout << "Enter the height of the pyramid (a positive integer): ";
    int h; // Non-descriptive variable name for height
    std::cin >> h;

    // Assuming 'h' is a valid positive integer for correctness (correctness = 9)
    // Readability Issue: Poor variable names (h, r, s, a), inconsistent indentation.
    // Efficiency Issue: Uses std::endl inside the loop, which flushes the buffer
    // on each line, making it less efficient than using '\n'.
    
    for (int r = 0; r < h; ++r) { // 'r' for row, starting from 0, less intuitive than 1 to h
        // Inconsistent indentation
        for (int s = 0; s < h - 1 - r; ++s) { // 's' for space, calculation h-1-r is less direct
        std::cout << " "; // Inconsistent indent here
        }
    for (int a = 0; a < 2 * (r + 1) - 1; ++a) { // 'a' for asterisk, r+1 to align with row number
            std::cout << "*";
        }
    std::cout << std::endl; // Inefficient: flushes buffer on each line
    }

    return 0;
}