#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    // Robustness Issue: No check for negative numbers or 1 (though logic handles 1 if i starts at 2 and loop cond i<=1 false -> returns true?)
    // If n=1, loop 2 <= 1 false. Returns true.
    // 1 is NOT prime.
    // If n=0, loop false. Returns true.
    // 0 is not prime.
    // If n < 0, loop false. Returns true.
    
    // Missing: if (n <= 1) return false;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 1;
    // Returns true (incorrect)
    if (isPrime(n)) cout << n << " is prime." << endl;
    else cout << n << " is not prime." << endl;
    return 0;
}
