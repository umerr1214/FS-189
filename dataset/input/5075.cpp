#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N;

    int sum = 0;
    // Logical Error: This loop sums ALL numbers from 1 to N, not just even numbers.
    for (int i = 1; i <= N; ++i) {
        sum += i;
    }

    std::cout << "Sum of even numbers between 1 and " << N << " is: " << sum << std::endl;
    return 0;
}