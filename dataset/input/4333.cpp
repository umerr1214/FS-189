#include <iostream>

int main() {
    int n;
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    long long sum = 0;
    // The problem statement specifies 'n' as a positive integer.
    // This code does not validate 'n' to ensure it is positive.
    // If 'n' is 0 or negative, the loop will not execute, and sum will remain 0.
    // While mathematically sum(1 to 0) is 0, and sum(1 to -X) is also 0,
    // this implicitly violates the problem's input constraint without explicit handling.
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    std::cout << "The sum of integers from 1 to " << n << " is: " << sum << std::endl;

    return 0;
}