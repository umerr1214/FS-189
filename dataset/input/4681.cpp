#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate (not used in this specific robustness example, but good to include)

// This solution attempts to read matrix dimensions and elements.
// It has a robustness issue where negative dimensions (specifically for columns)
// can lead to a `std::bad_alloc` or other undefined behavior due to
// `std::vector` attempting to allocate an extremely large amount of memory
// when a negative integer is implicitly converted to `size_t`.
int solution_main() {
    int rows, cols;
    long long totalSum = 0;

    // Read dimensions
    if (!(std::cin >> rows >> cols)) {
        std::cerr << "Error: Invalid input for matrix dimensions." << std::endl;
        return 1;
    }

    // Attempt to create the matrix.
    // If 'cols' is negative, it will be converted to a very large unsigned size_t,
    // leading to excessive memory allocation or a crash.
    // If 'rows' is negative, the outer loop will not execute, and totalSum will be 0,
    // which is arguably "correct" for an empty matrix, but `std::vector` constructor
    // would still attempt allocation if `cols` is positive.
    // The specific issue is with `std::vector<int> row(cols);`
    
    std::vector<std::vector<int>> matrix;
    try {
        matrix.reserve(rows > 0 ? rows : 0); // Reserve capacity, but actual construction is row by row
        for (int i = 0; i < rows; ++i) {
            // This is the problematic line if 'cols' is negative
            // `cols` (int) is implicitly converted to `size_t` for `std::vector` constructor.
            // A negative `int` becomes a very large `size_t`.
            std::vector<int> row(cols > 0 ? cols : 0); // Ensure non-negative size for vector construction
            for (int j = 0; j < cols; ++j) {
                int element;
                if (!(std::cin >> element)) {
                    std::cerr << "Error: Not enough elements or invalid element." << std::endl;
                    return 1;
                }
                row[j] = element;
                totalSum += element;
            }
            matrix.push_back(row);
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Error: Memory allocation failed. Likely due to large or negative dimensions. " << e.what() << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Out of range access. Likely due to invalid dimensions. " << e.what() << std::endl;
        return 1;
    }


    std::cout << totalSum << std::endl;

    return 0;
}