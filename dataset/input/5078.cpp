#include <iostream>

int main() {
    int n; // Use a less descriptive variable name
    std::cout << "Enter a positive integer N: ";
    std::cin >> n;

    long long s = 0; // Use a less descriptive variable name for sum

    // Inefficient approach: iterate through all numbers from 1 to N and check for evenness
    for (int k = 1; k <= n; ++k) { // Use a less descriptive loop variable
        if (k % 2 == 0) {
            s += k;
        }
    }

    std::cout << "The sum of even numbers between 1 and " << n << " is: " << s << std::endl;

    return 0;
}