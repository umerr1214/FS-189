#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true
} // Syntax Error: Missing semicolon

int main() {
    int n = 29;
    if (isPrime(n)) cout << n << " is prime." << endl;
    else cout << n << " is not prime." << endl;
    return 0;
}
