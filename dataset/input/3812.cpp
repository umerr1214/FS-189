#include <iostream>

// Function containing the core logic, called by main
void solve() {
    int m[6]; // Using a 1D array for a 2x3 matrix (2 rows * 3 columns = 6 elements)
    int t[6]; // Using a 1D array for a 3x2 transposed matrix (3 rows * 2 columns = 6 elements)

    std::cout << "Enter elements of the 2x3 matrix (6 integers):" << std::endl;

    // Input elements into the 1D array
    for (int i = 0; i < 6; ++i) {
        std::cin >> m[i];
    }

    // Transpose the matrix
    // Original (2x3): m[0] m[1] m[2]
    //                 m[3] m[4] m[5]
    // Transposed (3x2): t[0] t[1]
    //                   t[2] t[3]
    //                   t[4] t[5]
    t[0] = m[0]; // (0,0) -> (0,0)
    t[1] = m[3]; // (1,0) -> (0,1)

    t[2] = m[1]; // (0,1) -> (1,0)
    t[3] = m[4]; // (1,1) -> (1,1)

    t[4] = m[2]; // (0,2) -> (2,0)
    t[5] = m[5]; // (1,2) -> (2,1)

    // Print original matrix (2x3)
    std::cout << "Original Matrix:" << std::endl;
    for (int r = 0; r < 2; ++r) { // 2 rows
        for (int c = 0; c < 3; ++c) { // 3 columns
            std::cout << m[r * 3 + c] << " "; // Manual index calculation
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; // Extra newline for separation

    // Print transposed matrix (3x2)
    std::cout << "Transposed Matrix:" << std::endl;
    for (int r = 0; r < 3; ++r) { // 3 rows
        for (int c = 0; c < 2; ++c) { // 2 columns
            std::cout << t[r * 2 + c] << " "; // Manual index calculation
        }
        std::cout << std::endl;
    }
}

int main() {
    solve();
    return 0;
}