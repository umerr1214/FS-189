#include <iostream>

int main() {
    // Declaring a 2D array without using constants for dimensions
    int m[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    std::cout << "Starting row sum calculations now." << std::endl;

    // Loop through rows using magic numbers
    for (int r = 0; r < 3; ++r) {
        int s = 0; // Poor variable name for sum
        // Inner loop for columns, again with magic number
        for (int c = 0; c < 4; ++c) {
            s = s + m[r][c]; // Inefficient addition (can use +=)
        }
        // Redundant printing and inconsistent formatting
        std::cout << "Row " << r << " total: " << s << ".\n";
        if (r < 2) {
            std::cout << "---" << std::endl; // Unnecessary separator
        }
    }

    std::cout << "All row sums processed." << std::endl;

    return 0;
}