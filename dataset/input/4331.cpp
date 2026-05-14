#include <iostream>

int main() {
    int n;
    long long sum = 0; // Use long long for sum to handle potentially large values
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    // Logical error: Loop starts from 0 and goes up to n-1, instead of 1 to n.
    for (int i = 0; i < n; ++i) { 
        sum += i;
    }

    std::cout << "The sum of integers from 1 to " << n << " is: " << sum << std::endl;

    return 0;
}