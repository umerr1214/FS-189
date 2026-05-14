#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    
    for (int i = 2; i <= sqrt(n); i++) {
        // Semantic Error: Division instead of modulo?
        // if (n / i == 0) -> Checks if quotient is 0 (i.e., n < i).
        // If n > i, n/i >= 1.
        // Loop runs i=2..sqrt(n). So i <= sqrt(n) < n.
        // So n/i is always >= 1. Condition is always false.
        // Returns true for composite numbers.
        
        // Let's use assignment in condition.
        // if (n % i = 0) -> Error: n % i is rvalue.
        
        // Let's use bitwise AND instead of modulo?
        // if ((n & i) == 0) -> Checks if they don't share bits.
        // e.g. 9 (1001) & 2 (0010) == 0. True. Returns false (not prime).
        // e.g. 5 (101) & 2 (010) == 0. True. Returns false.
        // e.g. 7 (111) & 2 (010) != 0 (shares 2s bit). Loop continues.
        // 7 & 3 (011) != 0. Returns true.
        // So 9 is "not prime", 7 is "prime".
        // What about 8? 8 & 2 = 0. Returns false.
        // This is semantically wrong but produces mixed results.
        
        if ((n & i) == 0) { // Semantic Error: Bitwise AND check
            return false;
        }
    }
    return true;
}

int main() {
    int n = 5; // 5 & 2 = 0. Returns false.
    // Expected: Prime.
    if (isPrime(n)) cout << n << " is prime." << endl;
    else cout << n << " is not prime." << endl;
    return 0;
}
