#include <iostream>
using namespace std;

long long fibonacci(int n) {
    if (n < 0) return -1; // Error
    if (n <= 1) return n;
    
    // Iterative approach O(N)
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    cout << "Fib(10) = " << fibonacci(10) << endl; // 55
    cout << "Fib(0) = " << fibonacci(0) << endl; // 0
    cout << "Fib(-5) = " << fibonacci(-5) << endl; // -1
    return 0;
}
