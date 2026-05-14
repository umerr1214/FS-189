#include <iostream>

void solve() {
    int x; // Cryptic variable name for 'num'
    std::cout << "Enter an integer num: ";
    std::cin >> x;

    // Nested for loops with cryptic variable names and slightly less direct structure
    // Readability Issue: Poor variable names (x, y, z).
    // Efficiency Issue: The inner loop (for 'z') runs exactly once and is redundant.
    //                   The condition 'y <= 10' in the inner loop is also redundant
    //                   as it's already controlled by the outer loop.
    for (int y = 1; y <= 10; ++y) { // 'y' for multiplier
        for (int z = 0; z < 1 && y <= 10; ++z) { // 'z' for inner loop counter, redundant condition 'y <= 10'
            std::cout << x << " * " << y << " = " << (x * y) << std::endl;
        }
    }
}

int main() {
    solve();
    return 0;
}