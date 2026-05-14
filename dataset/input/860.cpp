#include <iostream>
using namespace std;

int gcd(int a, int b) {
    // Logical Error: Incorrect recursive step logic.
    // Instead of gcd(b, a % b), using gcd(a % b, b) or swapping without modulo?
    // Or just incorrect base case.
    
    // Error: Infinite recursion or wrong calculation by not reducing problem correctly.
    // Let's use subtraction algorithm but incorrectly?
    // Or `gcd(b % a, a)`?
    
    if (b == 0) return a;
    return gcd(a, b % a); // Logical error: swapping arguments incorrectly or modulo order
    // If a < b, a % b is a. gcd(a, b) calls gcd(a, b%a) -> gcd(a, b) if a < b?
    // Wait. 48, 18.
    // gcd(48, 18%48) -> gcd(48, 18).
    // gcd(48, 18%48) -> gcd(48, 18).
    // Infinite recursion if a > b? No, if b < a.
    // 48 % 18 = 12. Correct is gcd(18, 12).
    // Here: gcd(48, 18 % 48) -> gcd(48, 18).
    // Infinite loop!
}

int main() {
    int a = 48, b = 18;
    // Expected: 6
    // Actual: Stack Overflow (Infinite Recursion)
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}
