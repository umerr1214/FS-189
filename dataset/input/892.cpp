#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    // Robustness Issue: No check for negative numbers.
    // If n is negative, n > 0 is false immediately. Returns 0.
    // Sum of digits for -123 should probably be 6 (ignoring sign) or handle it.
    // Or if loop condition was `n != 0`, `n % 10` for negative numbers can be negative.
    // -123 % 10 = -3. Sum becomes -3. n becomes -12.
    // Final sum -6.
    
    // But here `while (n > 0)` returns 0 for negative input.
    // Robustness: Should handle negative input (e.g., take abs).
    
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    // Returns 0. 
    cout << "Sum of -123: " << sumOfDigits(-123) << endl;
    return 0;
}
