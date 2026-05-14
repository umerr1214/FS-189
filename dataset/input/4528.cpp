#include <iostream>
#include <vector>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N // Missing semicolon here

    if (N < 1) {
        std::cout << "N must be a positive integer." << std::endl;
        return 1;
    }

    std::cout << "Prime numbers up to " << N << ":" << std::endl;
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}