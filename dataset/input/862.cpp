#include <iostream>
using namespace std;

int gcd(int a, int b) {
    // Robustness Issue: Handling negative numbers?
    // GCD of negative numbers usually defined as positive.
    // e.g. gcd(-48, 18) should be 6.
    // a % b in C++ with negatives: -48 % 18 = -12.
    // gcd(18, -12) -> gcd(-12, 18 % -12) -> gcd(-12, 6) -> gcd(6, -12 % 6) -> gcd(6, 0) -> 6.
    // It actually works for this case but might return negative if not careful?
    // If b is negative?
    // gcd(48, -18). 48 % -18 = 12. gcd(-18, 12) -> gcd(12, -18 % 12) -> gcd(12, -6) -> gcd(-6, 0) -> -6.
    // Returns -6. GCD should be positive.
    
    // Also, what if a=0, b=0? Undefined (or 0).
    // The code `a % b` crashes if b=0? No, `if (b==0)` check prevents it.
    // But `a % 0` is undefined.
    // Robustness: ensure positive result.
    
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a = 48, b = -18;
    // Returns -6
    cout << "GCD: " << gcd(a, b) << endl;
    return 0;
}
