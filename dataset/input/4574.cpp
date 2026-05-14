#include <iostream>
#include <iomanip>

// No constants for dimensions, hardcoded '3'
// Poor variable names

int main() {
    int m[3][3] = { // 'm' for matrix
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int s; // 's' for scalar
    int r[3][3]; // 'r' for result

    std::cout << "Enter a scalar value: "; // Shorter prompt
    std::cin >> s;

    for (int i = 0; i < 3; ++i) { // Hardcoded '3'
        for (int j = 0; j < 3; ++j) { // Hardcoded '3'
            r[i][j] = m[i][j] * s;
        }
    }

    std::cout << "Result:\n"; // Shorter output message
    for (int i = 0; i < 3; ++i) { // Hardcoded '3'
        for (int j = 0; j < 3; ++j) { // Hardcoded '3'
            std::cout << std::setw(4) << r[i][j]; // Using setw is good, but overall readability is low
        }
        std::cout << std::endl; // Using std::endl which flushes, slightly less efficient than '\n' in a tight loop
    }

    return 0;
}