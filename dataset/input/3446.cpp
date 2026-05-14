#include <iostream>
#include <vector> // Included for general C++ practice, though not strictly needed for fixed-size C-array
#include <algorithm> // Not used, could be an efficiency improvement if std::max was used

void solve() {
    const int S = 5; // Cryptic variable name for SIZE
    int a[S];        // Short, non-descriptive variable name for array

    std::cout << "Enter " << S << " nums:\n"; // Non-descriptive prompt

    for (int x = 0; x < S; ++x) { // Short loop variable 'x'
        std::cout << "Num " << x + 1 << ": ";
        std::cin >> a[x];
    }

    // Minor inefficiency: Initialize 'm' with a[0] and then iterate from x=0,
    // causing a[0] to be compared with itself unnecessarily.
    // Also, not using std::max for finding the maximum element.
    int m = a[0]; // Short, non-descriptive variable name for largest element
    for (int x = 0; x < S; ++x) { // Iterate from 0, could be 1 for slight efficiency gain
        if (a[x] > m) {
            m = a[x];
        }
    }

    std::cout << "Largest is: " << m << "\n"; // Non-descriptive output
}

int main() {
    solve();
    return 0;
}