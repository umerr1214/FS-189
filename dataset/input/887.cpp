#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    // Efficiency Issue: Iterating up to n/2 instead of sqrt(n).
    // O(N) instead of O(sqrt(N)).
    // For large N, this is significantly slower.
    
    if (n <= 1) return false;
    
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 29;
    if (isPrime(n)) cout << n << " is prime." << endl;
    else cout << n << " is not prime." << endl;
    return 0;
}
