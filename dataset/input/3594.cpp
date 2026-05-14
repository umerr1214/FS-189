#include <iostream>
#include <limits> // Required for numeric_limits if used, though not directly in this simplified case

void solve() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    for (int i = 1; i <= 10; ++i) {
        // Semantic error: The result of multiplication (num * i) is stored in a 'short'
        // type, which has a smaller range than 'int'. For larger input numbers,
        // this can cause integer overflow, leading to incorrect values due to truncation or wrap-around.
        short product = num * i; // Implicit conversion from int to short
        std::cout << num << " x " << i << " = " << product << std::endl;
    }
}

int main() {
    solve();
    return 0;
}