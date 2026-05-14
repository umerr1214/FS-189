#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true; // 2 and 3 are prime
    
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Optimization: Check only 6k +/- 1
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "2: " << isPrime(2) << endl; // 1
    cout << "9: " << isPrime(9) << endl; // 0
    cout << "17: " << isPrime(17) << endl; // 1
    cout << "1: " << isPrime(1) << endl; // 0
    return 0;
}
