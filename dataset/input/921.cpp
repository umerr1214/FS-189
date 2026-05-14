#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    
    // Semantic Error: bitwise OR instead of addition?
    // Or assignment in expression?
    
    // Let's use bitwise OR `|`.
    return fibonacci(n - 1) | fibonacci(n - 2); 
}

int main() {
    int n = 5;
    // f(0)=0, f(1)=1
    // f(2) = 1 | 0 = 1
    // f(3) = 1 | 1 = 1
    // f(4) = 1 | 1 = 1
    // f(5) = 1 | 1 = 1
    // Result 1. Expected 5.
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
