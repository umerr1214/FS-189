#include <iostream>

void solve_question() {
    int x; // Poor variable name for N
    int y = 0; // Poor variable name for sum
    int z = 1; // Poor variable name for current number

    std::cout << "Enter a positive integer N: ";
    std::cin >> x;

    // Basic check to prevent issues for non-positive N, but not robust error handling
    if (x <= 0) {
        std::cout << "The sum of odd numbers from 1 to " << x << " is: " << 0 << std::endl;
        return;
    }

    // Efficiency issue: Iterates through all numbers from 1 to x, checking for oddness.
    // This performs 'x' iterations (approximately) instead of 'x/2' iterations
    // if it were to directly iterate only odd numbers.
    // Readability issue: Variable names 'x', 'y', 'z' are not descriptive and make the code harder to understand.
    while (z <= x) {
        if (z % 2 != 0) { // Check if z is odd
            y = y + z;
        }
        z = z + 1; // Increment z by 1 each time
    }

    std::cout << "The sum of odd numbers from 1 to " << x << " is: " << y << std::endl;
}

int main() {
    solve_question();
    return 0;
}