#include <iostream>

int main() {
    int m[3][3]; // Matrix declaration with magic numbers
    int i, j; // Poorly named loop variables

    std::cout << "Enter 9 numbers for the 3x3 matrix:\n";

    // Input loop - no comments for clarity
    for (i = 0; i < 3; ++i) { // Using magic number 3
        for (j = 0; j < 3; ++j) { // Using magic number 3
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> m[i][j];
        }
    }

    std::cout << "\nMatrix contents:\n";
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            std::cout << m[i][j] << "\t";
        }
        std::cout << "\n"; // Using \n instead of std::endl for slightly better efficiency, but inconsistent with other outputs
    }

    std::cout << "\nRow sums:\n";

    // Calculate and print row sums
    for (i = 0; i < 3; ++i) {
        int s = 0; // Poorly named sum variable
        for (j = 0; j < 3; ++j) {
            s += m[i][j];
        }
        std::cout << "Row " << i << " sum is: " << s << std::endl;
    }

    return 0;
}