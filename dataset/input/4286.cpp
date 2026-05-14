#include <iostream>
#include <vector>

// Function with readability and efficiency issues
void sm_rw(int** m, int r, int c) {
    for (int x = 0; x < r; ++x) { // Bad variable names: 'x' for row index
        int s = 0; // Short variable name 's' for sum
        for (int y = 0; y < c; ++y) { // Bad variable names: 'y' for column index; inconsistent spacing
            s += m[x][y]; // Inconsistent spacing around operator
        }
        std::cout << "Row " << x << " sum: " << s << std::endl; // Inefficient use of std::endl (flushes buffer)
    }
}

int main() {
    // Example usage for compilation and basic check
    int R = 3; // Inconsistent variable casing
    int C = 2;
    int** M = new int*[R];
    for (int i = 0; i < R; ++i) {
        M[i] = new int[C];
        for (int j = 0; j < C; ++j) {
            M[i][j] = (i + 1) * (j + 1); // Fills with 1 2, 2 4, 3 6
        }
    }

    std::cout << "--- Readability/Efficiency Test ---\n";
    sm_rw(M, R, C);

    // Clean up
    for (int i = 0; i < R; ++i) {
        delete[] M[i];
    }
    delete[] M;

    return 0;
}