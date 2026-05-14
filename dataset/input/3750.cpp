#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N;
    
    if (N <= 0) {
        std::cout << "N must be a positive integer." << std::endl;
        return 1;
    }

    // Semantic Error: Using 'int' for 'sum' can lead to integer overflow
    // if N is large enough (e.g., N=100,000, sum of odds is 2,500,000,000,
    // which exceeds typical INT_MAX of 2,147,483,647).
    // 'sum' should be 'long long' to correctly store large sums.
    int sum = 0; 
    int current_num = 1;

    while (current_num <= N) {
        if (current_num % 2 != 0) { // Check if current_num is odd
            sum += current_num;
        }
        current_num++;
    }

    std::cout << "The sum of odd numbers from 1 to " << N << " is: " << sum << std::endl;

    return 0;
}