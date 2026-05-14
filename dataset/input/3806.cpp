#include <iostream>

int main() {
    int m[3][3] = { // Poor variable name 'm'
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "Calculating row sums:" << std::endl;
    for (int r = 0; r < 3; ++r) { // 'r' for row, 'c' for column - poor names
        int rs = 0; // 'rs' for row sum - poor name
        for (int c = 0; c < 3; ++c) {
            rs += m[r][c];
        }
        std::cout << "Row " << r << " sum: " << rs << "\n"; // Inconsistent use of \n vs std::endl
    }

    std::cout << "Calculating column sums:" << std::endl;
    // Inefficient: Re-iterating the entire matrix just for column sums, leading to redundant computations
    for (int c = 0; c < 3; ++c) {
        int cs = 0; // 'cs' for column sum - poor name
        for (int r = 0; r < 3; ++r) {
            cs += m[r][c];
        }
        std::cout << "Column " << c << " sum: " << cs << "\n";
    }

    return 0;
}