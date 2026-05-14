#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N;
    
    if (N <= 0) {
        std::cout << "N must be a positive integer." << std::endl;
        return 1;
    }

    int sum = 0;
    int current_num = 1;

    while (current_num <= N) {
        // Logical Error: This program sums ALL numbers from 1 to N,
        // instead of only the odd numbers.
        sum += current_num; 
        current_num++;
    }

    std::cout << "The sum of odd numbers from 1 to " << N << " is: " << sum << std::endl;

    return 0;
}