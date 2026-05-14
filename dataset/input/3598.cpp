#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N // Syntax Error: Missing semicolon here

    if (N < 1) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    int sum = 0;
    int i = 1;
    while (i <= N) {
        sum += i;
        i++;
    }

    std::cout << "The sum of natural numbers up to " << N << " is: " << sum << std::endl;

    return 0;
}