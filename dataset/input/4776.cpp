#include <iostream>

// Function to calculate sum of odd numbers
int calculateSumOfOdds(int N) {
    // Semantic Error: Using 'short int' for sum.
    // A 'short int' typically has a maximum value of 32767.
    // For N=400, the sum of odd numbers is 40000, which will cause an integer overflow,
    // leading to an incorrect result (e.g., -25536 on systems where short is 16-bit).
    short int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            sum += i;
        }
    }
    return sum; // The overflow happens before the return, and the (potentially incorrect) value is then cast to int.
}

int main() {
    int N;
    std::cin >> N; // Read N directly

    if (N < 1) {
        // Per question, N is a positive integer. For N<1, sum is 0.
        // However, this simple program will just output 0 from the function.
        // For test cases, N will be positive.
    }

    std::cout << calculateSumOfOdds(N) << std::endl;
    return 0;
}