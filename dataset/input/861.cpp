#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    
    // Semantic Error: bitwise OR instead of modulo?
    // Or division `/` instead of modulo `%`?
    // Division returns quotient, modulo returns remainder.
    // Using division changes the algorithm completely.
    
    return gcd(b, a / b); // Semantic Error: Division instead of Modulo
}

int main() {
    int a = 48, b = 18;
    // Expected: 6
    // Actual: 
    // gcd(18, 48/18) -> gcd(18, 2)
    // gcd(2, 18/2) -> gcd(2, 9)
    // gcd(9, 2/9) -> gcd(9, 0) -> returns 9.
    // Incorrect result.
    
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}
