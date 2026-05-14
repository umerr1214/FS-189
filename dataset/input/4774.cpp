#include <iostream>

// Function to calculate sum of odd numbers
int calculateSumOfOdds(int N) {
    long long sum = 0; // Use long long to prevent potential overflow for very large N, though int is sufficient for typical N.
    for (int i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int N;
    std::cin >> N; // Read N directly

    // Syntax Error: Missing semicolon at the end of the following line
    std::cout << calculateSumOfOdds(N) << std::endl
    return 0;
}