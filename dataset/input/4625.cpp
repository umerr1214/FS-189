#include <iostream>

int main() {
    int n;
    long long sum = 0; 
    std::cout << "Enter a positive integer 'n': ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    // Logical error: loop iterates from 1 to n-1, excluding 'n'
    for (int i = 1; i < n; ++i) { // Should be i <= n
        sum += i;
    }

    std::cout << "The sum of natural numbers from 1 to " << n << " is: " << sum << std::endl;

    return 0;
}