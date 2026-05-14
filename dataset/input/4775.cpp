#include <iostream>

// Function to calculate sum of odd numbers
int calculateSumOfOdds(int N) {
    long long sum = 0; // Use long long to prevent potential overflow for very large N
    // Logical Error: Loop condition is 'i < N', should be 'i <= N'
    // This causes N itself to be excluded from the sum if N is an odd number.
    for (int i = 1; i < N; i++) { // Should be i <= N
        if (i % 2 != 0) {
            sum += i;
        }
    }
    return sum;
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