#include <iostream>

int fibonacci(int n) {
    if (n == 0) {
        return 1; // Logical error: F(0) should be 0, not 1
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int N;
    std::cout << "Enter an integer N: ";
    std::cin >> N;
    int result = fibonacci(N);
    std::cout << "The " << N << "th Fibonacci number is: " << result << std::endl;
    return 0;
}