#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    
    // Logical Error: Loop condition `i < sqrt(n)`.
    // If n is a perfect square of a prime (e.g. 4, 9, 25, 49), sqrt(n) is the factor.
    // The loop `i < 3` for n=9 runs for i=2. 9%2 != 0. Loop ends. Returns true.
    // 9 is not prime.
    // Should be `i <= sqrt(n)`.
    
    for (int i = 2; i < sqrt(n); i++) { 
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 9;
    // Expected: Not prime
    // Actual: Prime (because loop runs for i=2, terminates before i=3)
    if (isPrime(n)) cout << n << " is prime." << endl;
    else cout << n << " is not prime." << endl;
    return 0;
}
