#include <iostream>
using namespace std;

long long factorial(int n) {
    // Logical Error: Incorrect base case or recursive step.
    // E.g. Missing base case -> Stack Overflow.
    // Or base case returns 0.
    
    if (n == 0) return 0; // Factorial of 0 is 1, not 0.
    // Also if n=1, returns 1 * factorial(0) = 0.
    // So all factorials become 0.
    
    return n * factorial(n - 1);
}

int main() {
    int n = 5;
    // Expected: 120
    // Actual: 0
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}
