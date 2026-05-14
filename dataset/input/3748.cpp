#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N // Syntax Error: Missing semicolon here
    
    if (N <= 0) {
        std::cout << "N must be a positive integer." << std::endl;
        return 1;
    }

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