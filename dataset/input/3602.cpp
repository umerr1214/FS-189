#include <iostream>

void solve() {
    int n_val; // Poor variable name for N
    long long total_sum = 0; // Overly verbose variable name
    int curr_num = 1; // Poor variable name for loop counter

    std::cout << "Enter a positive integer for N: \n"; // Slightly verbose prompt
    std::cin >> n_val;

    std::cout << "Calculating sum...\n"; // Unnecessary intermediate output

    // The logic correctly calculates the sum using a while loop.
    // However, variable names reduce readability.
    while (curr_num <= n_val) {
        total_sum += curr_num;
        curr_num++;
    }

    std::cout << "Sum of numbers up to " << n_val << " is: " << total_sum << "\n"; // Slightly verbose output
}

int main() {
    solve();
    return 0;
}