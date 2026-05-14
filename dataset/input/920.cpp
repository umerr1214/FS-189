#include <iostream>
using namespace std;

int fibonacci(int n) {
    // Logical Error: Incorrect recursive step.
    // e.g. fib(n-1) * fib(n-2) or fib(n-1) + fib(n-1).
    // Or base case error.
    
    if (n <= 1) return n;
    return fibonacci(n - 1) * fibonacci(n - 2); // Multiplication instead of addition
}

int main() {
    int n = 5;
    // Expected: 5 (0, 1, 1, 2, 3, 5)
    // Actual: 
    // f(0)=0, f(1)=1.
    // f(2) = f(1)*f(0) = 1*0 = 0.
    // f(3) = f(2)*f(1) = 0*1 = 0.
    // Always 0 for n >= 2.
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
