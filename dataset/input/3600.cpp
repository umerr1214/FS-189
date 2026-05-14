#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N;

    if (N < 1) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    char sum = 0; // Semantic Error: 'sum' is declared as 'char', which can overflow for larger N.
                  // 'int' should be used for sums of natural numbers to prevent overflow.
    int i = 1;
    while (i <= N) {
        sum += i;
        i++;
    }

    // Explicitly cast sum to int for printing to observe the wrapped-around value if overflow occurs.
    std::cout << "The sum of natural numbers up to " << N << " is: " << (int)sum << std::endl;

    return 0;
}