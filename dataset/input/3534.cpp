#include <iostream>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // This recursive sum can lead to integer overflow for large N
        // because 'int' has a limited range.
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int N;
    std::cout << "Enter an integer N: ";
    std::cin >> N;
    int result = fibonacci(N); // 'result' might store an overflowed value if N is large
    std::cout << "The " << N << "th Fibonacci number is: " << result << std::endl;
    return 0;
}