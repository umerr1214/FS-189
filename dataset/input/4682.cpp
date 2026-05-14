#include <iostream>
#include <vector>
#include <numeric> // Included but not used efficiently
#include <string> // For getline, if needed (not in this version)

// This program calculates the sum of matrix elements but suffers from
// readability and efficiency issues.
// Readability: Poor variable names, lack of comments, somewhat convoluted approach.
// Efficiency: Reads all elements into a single 1D vector first, then iterates
//            through it using 2D indexing, adding an extra layer of indirection
//            and memory compared to directly filling and summing a 2D vector.
int solution_main() {
    int R, C; // R for rows, C for columns - somewhat ambiguous single letters
    long long T = 0; // T for total sum - not very descriptive

    // Get dims
    std::cin >> R >> C;

    // Use a 1D vector to store all elements, then access them as if 2D
    // This is less efficient for direct 2D access than a vector of vectors.
    std::vector<int> V(R * C); // V for vector, not descriptive

    // Read all elements into the flat vector
    for (int k = 0; k < R * C; ++k) { // k for index, common but not explicit
        std::cin >> V[k];
    }

    // Calculate sum using 2D logic on the 1D vector
    for (int i = 0; i < R; ++i) { // i for row index
        for (int j = 0; j < C; ++j) { // j for column index
            T += V[i * C + j]; // Accessing elements using 2D logic on 1D array
        }
    }

    std::cout << T << std::endl; // std::endl flushes, less efficient than '\n'

    return 0;
}