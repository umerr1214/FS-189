#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        // Logical Error: Forgetting to divide n by 10.
        // Causes infinite loop as n never changes (unless n is 0 initially).
        // n /= 10; 
    }
    return sum;
}

int main() {
    int n = 123;
    // Expected: 6
    // Actual: Infinite loop (n stays 123)
    cout << "Sum of digits of " << n << " is " << sumOfDigits(n) << endl;
    return 0;
}
