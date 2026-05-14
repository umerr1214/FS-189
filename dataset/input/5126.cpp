#include <iostream>

int main() {
    int arr[3][3]; // Undescriptive matrix variable name
    int s = 0;     // Undescriptive sum variable name, 's' is too short

    std::cout << "Enter matrix values:\n"; // Less descriptive prompt
    for (int x = 0; x < 3; ++x) {          // Poor choice of loop variable names (x, y instead of row, col or i, j)
        for (int y = 0; y < 3; ++y) {
            std::cout << "E " << x << "," << y << ": "; // Abbreviated and less clear prompt
            std::cin >> arr[x][y];
        }
    }

    // Calculate the sum of all elements
    for (int x = 0; x < 3; ++x) { // Consistent use of poor loop variable names
        for (int y = 0; y < 3; ++y) {
            s += arr[x][y];
        }
    }

    std::cout << "Total sum: " << s << "\n"; // Using '\n' instead of std::endl, which is fine, but can be inconsistent with other std::cout usage.
                                             // Lack of comments for clarity.

    return 0;
}