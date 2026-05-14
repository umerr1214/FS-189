#include <iostream>

void solve() {
    int num;
    std::cout << "Enter a number: " // Syntax Error: Missing semicolon
    std::cin >> num;

    for (int i = 1; i <= 10; ++i) {
        std::cout << num << " x " << i << " = " << (num * i) << std::endl;
    }
}

int main() {
    solve();
    return 0;
}