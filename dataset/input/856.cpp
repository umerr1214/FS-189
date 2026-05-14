#include <iostream>
using namespace std;

void printPascalsTriangle(int n) {
    // Robustness Issue: No check for negative n.
    // Also, integer overflow for large n (e.g. n=30, middle terms exceed 2 billion).
    // Using `int` for C is risky for n > 30. `long long` is better.
    
    // If n < 0, loop doesn't run, which is safe.
    // But overflow is the main robustness issue for Pascal's Triangle.
    
    for (int line = 1; line <= n; line++) {
        int C = 1; // Overflow here if n is large
        for (int i = 1; i <= line; i++) {
            cout << C << " ";
            C = C * (line - i) / i;
        }
        cout << endl;
    }
}

int main() {
    // n=34 causes overflow for 32-bit int (C(34, 17) > 2*10^9)
    printPascalsTriangle(35); 
    return 0;
}
