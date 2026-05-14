#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1) return 1;
    
    // Semantic Error: bitwise XOR instead of multiplication?
    // Or division.
    
    // Let's use addition.
    // return n + factorial(n - 1); // Calculates sum 1..n instead of product.
    
    // Let's use bitwise AND.
    // return n & factorial(n-1);
    
    // Let's use assignment in expression.
    // return n = factorial(n-1); // Modifies n?
    
    // Let's use division.
    return n / factorial(n - 1); // Semantic error: Division logic
}

int main() {
    int n = 5;
    // Expected: 120
    // Actual: 
    // f(1) = 1
    // f(2) = 2 / 1 = 2
    // f(3) = 3 / 2 = 1
    // f(4) = 4 / 1 = 4
    // f(5) = 5 / 4 = 1
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}
