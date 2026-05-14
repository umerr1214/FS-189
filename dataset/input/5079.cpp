#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";

    // Robust input reading: ensure a valid integer is entered
    while (!(std::cin >> N)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flags
        std::cin.ignore(10000, '\n'); // Discard invalid input
    }

    long long sumOfEvenNumbers = 0; // Use long long for sum to prevent potential overflow for large N

    // Efficient approach: iterate directly through even numbers
    // The loop correctly handles N=1 (sum=0) and N<=0 (sum=0) as there are no even numbers between 1 and N.
    for (int i = 2; i <= N; i += 2) {
        sumOfEvenNumbers += i;
    }

    std::cout << "The sum of even numbers between 1 and " << N << " is: " << sumOfEvenNumbers << std::endl;

    return 0;
}