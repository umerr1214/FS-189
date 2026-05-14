#include <iostream>

void solve() {
    int num;
    std::cout << "Enter an integer num: ";
    // Robustness Issue: No check for cin.fail() or clearing the error state.
    // If non-integer input is provided, cin will enter a fail state,
    // num will remain uninitialized or contain garbage, and subsequent
    // output will be incorrect or unexpected.
    std::cin >> num; 

    // Nested for loops as strictly required by the question
    // The inner loop runs exactly once to fulfill the 'nested for loops' requirement.
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j < 1; ++j) { // Inner loop runs once for each 'i'
            std::cout << num << " * " << i << " = " << (num * i) << std::endl;
        }
    }
}

int main() {
    solve();
    return 0;
}