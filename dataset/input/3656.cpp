#include <iostream>

// Matrix definition with hardcoded size, no constants used
int mx[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
};

int main() {
    int r_idx; // Obscure variable name for row index
    if (!(std::cin >> r_idx)) {
        std::cerr << "Input fail." << std::endl; // Less descriptive error message
        return 1;
    }

    int t_sum = 0; // Obscure variable name for total sum
    
    // Hardcoded dimensions (4 for rows, 3 for columns) directly in conditional and loop
    // No dedicated function for the core logic
    if (r_idx >= 0 && r_idx < 4) { // Hardcoded '4' for row count
        for (int c_itr = 0; c_itr < 3; ++c_itr) { // Hardcoded '3' for column count, obscure iterator name
            t_sum += mx[r_idx][c_itr];
        }
        std::cout << t_sum << std::endl;
    } else {
        std::cerr << "Row index out of acceptable range." << std::endl; // Less specific message
        return 1;
    }

    return 0;
}