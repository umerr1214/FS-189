#include <iostream>

void solve() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    for (int i = 1; i <= 10; ++i) {
        // Logical error: The program performs addition instead of multiplication
        std::cout << num << " x " << i << " = " << (num + i) << std::endl;
    }
}

int main() {
    solve();
    return 0;
}