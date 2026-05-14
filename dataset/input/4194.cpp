#include <iostream>
#include <string>

int main() {
    int n;
    std::cout << "Enter the height of the pyramid: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer for the height." << std::endl;
        return 1;
    }

    // The loop iterates from 0 to n (inclusive), meaning it will print n+1 rows
    // instead of the requested 'n' rows for the height.
    for (int i = 0; i <= n; ++i) { 
        // Print spaces
        for (int j = 0; j < n - 1 - i; ++j) {
            std::cout << " ";
        }
        // Print stars
        for (int k = 0; k < 2 * i + 1; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}