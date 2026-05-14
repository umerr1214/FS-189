#include <iostream>
#include <limits> // Required for CHAR_MAX or INT_MAX if using them for explanation

int main() {
    int n; 
    long long sum = 0; 
    std::cout << "Enter a positive integer 'n': ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    // Semantic error: Using 'char' as loop counter 'i'.
    // While it works for small values of 'n' (e.g., n <= 127 on most systems),
    // if 'n' exceeds the maximum value a 'char' can hold,
    // 'i' will eventually overflow and wrap around, leading to an infinite loop or incorrect sum.
    // This is a semantic error because the chosen type for 'i' does not correctly
    // represent the potential range of values required by the loop condition 'i <= n'.
    for (char i = 1; i <= n; ++i) { 
        sum += i;
    }

    std::cout << "The sum of natural numbers from 1 to " << n << " is: " << sum << std::endl;

    return 0;
}