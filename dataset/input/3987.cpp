#include <iostream>
#include <vector> // Using std::vector for a more modern C++ approach to 2D arrays
#include <numeric> // For std::accumulate, a more concise way to sum elements

int main() {
    // Define matrix dimensions using named constants for clarity and maintainability
    const int ROWS = 3;
    const int COLS = 4;

    // Create and initialize a 3x4 integer matrix (2D array) using std::vector of std::vector
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    std::cout << "Calculating and printing the sum of elements for each row:" << std::endl;

    // Iterate through each row to calculate its sum
    for (int i = 0; i < ROWS; ++i) {
        int rowSum = 0;
        // Sum elements of the current row
        // Using std::accumulate for conciseness and efficiency,
        // or a traditional loop for clarity. Let's use a traditional loop
        // to keep it consistent with the previous examples' style, but make it clean.
        for (int j = 0; j < COLS; ++j) {
            rowSum += matrix[i][j];
        }
        // Or using std::accumulate:
        // int rowSum = std::accumulate(matrix[i].begin(), matrix[i].end(), 0);

        // Print the sum for the current row
        std::cout << "Sum of Row " << i << ": " << rowSum << std::endl;
    }

    std::cout << "Matrix row sums calculated successfully." << std::endl;

    return 0;
}