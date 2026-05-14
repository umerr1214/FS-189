#include <iostream>
#include <vector>
#include <string>

// Inefficient recursive function to calculate the k-th Fibonacci number.
// It recomputes the same values multiple times, leading to exponential time complexity.
// The function name 'g' is not very descriptive.
long long g(int k) {
    if (k <= 0) return 0;
    if (k == 1) return 1;
    return g(k - 1) + g(k - 2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n; // User input for the number of terms
    std::cin >> n;

    if (n <= 0) { // Handles non-positive input by printing nothing
        return 0;
    }

    // Prints the first term (F_0)
    std::cout << 0;

    // Loops to generate and print subsequent terms (F_1 to F_{n-1})
    for (int i = 1; i < n; ++i) {
        // Calls the inefficient recursive function 'g' for each term,
        // significantly impacting performance for larger 'n'.
        std::cout << " " << g(i);
    }
    std::cout << std::endl;

    return 0;
}