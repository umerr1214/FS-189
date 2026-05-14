#include <iostream>

int main() {
    int num_rows; // Variable name is 'num_rows' but could be more descriptive or consistent with 'N'.
    std::cout << "Enter the number of rows: ";
    std::cin >> num_rows;

    // Readability issue: Using less descriptive single-letter variable names 'r' and 'c'.
    // Efficiency issue: Using std::endl instead of '\n', which flushes the buffer
    // on each line, potentially slowing down output for large N.
    for (int r = 1; r <= num_rows; r++) { // Using r++ instead of ++r (minor style point)
        for (int c = 1; c <= r; c++) {
            std::cout << "*";
        }
        std::cout << std::endl; // Efficiency issue: std::endl flushes the buffer.
    }

    return 0;
}