#include <iostream>

int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int sum = 0;
    // Semantic Error: Loop condition 'i <= 4' causes an out-of-bounds access.
    // For a 4x4 matrix (indices 0-3), accessing matrix[4][4] is undefined behavior.
    for (int i = 0; i <= 4; ++i) {
        sum += matrix[i][i]; // Accesses matrix[4][4] on the last iteration
    }

    std::cout << "Sum of main diagonal elements: " << sum << std::endl;

    return 0;
}