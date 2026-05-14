#include <iostream>
#include <string>

int main() {
    int numRows; // User-specified number of rows
    std::cin >> numRows;

    // Readability / Efficiency Issue:
    // 1. Using 'char' for loop counters 'r_idx' and 'c_idx' is unusual and less readable,
    //    and could lead to overflow issues if 'numRows' were extremely large (though unlikely for patterns).
    //    'int' is the standard and clearer choice.
    // 2. Variable names like 'r_idx' and 'c_idx' are slightly less intuitive than 'row' and 'col' for simple loops.
    // 3. Using `std::endl` (which flushes the buffer) at the end of each row is slightly less efficient
    //    than using `'\n'` (which typically doesn't flush immediately), especially for a large number of rows.
    //    While not a major performance bottleneck here, it's a common micro-optimization.

    for (char r_idx = 1; r_idx <= numRows; ++r_idx) { // Outer loop for each row
        char c_idx = 1; // Initialize inner loop counter
        while (c_idx <= r_idx) { // Inner loop for printing asterisks in the current row
            std::cout << "*";
            c_idx++;
        }
        std::cout << std::endl; // New line after each row, with flush
    }

    return 0;
}