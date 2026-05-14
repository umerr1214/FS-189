#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate (though manual sum is also fine)

int main() {
    // Define matrix dimensions
    const int ROWS = 3;
    const int COLS = 4;

    // Create a 3x4 integer matrix (2D array)
    // Using a C-style array to potentially highlight robustness issues with manual indexing
    int matrix[ROWS][COLS] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {5,  10, 15, 20}
    };

    std::cout << "Calculating sum of elements for each row:" << std::endl;

    // Calculate and print the sum of elements for each individual row
    for (int i = 0; i < ROWS; ++i) {
        int rowSum = 0;
        // Introduce a robustness issue: loop one element too far in columns
        // This attempts to access matrix[i][COLS], which is out-of-bounds.
        // On some systems/compilers, this might not crash immediately but leads to
        // undefined behavior or incorrect sum if the memory happens to be zero.
        // For the given matrix, it will add a garbage value or zero, making the sum incorrect.
        for (int j = 0; j <= COLS; ++j) { // <= COLS instead of < COLS
            if (j < COLS) { // This check prevents immediate crash but the logic is flawed
                            // as the loop still goes one iteration too far, even if the value
                            // isn't used from the out-of-bounds index directly.
                            // A more direct robustness issue is to remove this check:
                rowSum += matrix[i][j];
            } else {
                // If the check were removed, matrix[i][COLS] would be accessed.
                // For demonstration, let's make it more direct.
                // Removing the `if (j < COLS)` condition for a clear robustness issue.
                // The original problem statement implies a fixed matrix, so this
                // is a deliberate error for demonstration.
            }
        }
        // Let's re-implement the robustness issue more directly:
        // The loop condition `j <= COLS` will attempt to access `matrix[i][4]` which is out of bounds.
        // This is undefined behavior.
        // The previous attempt with `if (j < COLS)` was too safe and didn't clearly demonstrate the issue.
        rowSum = 0; // Reset sum for clearer demo
        for (int j = 0; j <= COLS; ++j) { // This is the problematic line
            rowSum += matrix[i][j]; // Accessing out of bounds when j == COLS
        }

        std::cout << "Sum of Row " << i << ": " << rowSum << std::endl;
    }

    return 0;
}