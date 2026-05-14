#include <iostream>
using namespace std;

void printPascalsTriangle(int n) {
    for (int line = 1; line <= n; line++) {
        int C = 1;
        for (int i = 1; i <= line; i++) {
            cout << C << " ";
            // Logical Error: Incorrect formula for next binomial coefficient.
            // Correct is C = C * (line - i) / i
            // Let's use multiplication instead of division or wrong terms.
            C = C * (line - i) * i; // Wrong formula
        }
        cout << endl;
    }
}

int main() {
    // Expected Row 3: 1 2 1
    // Actual with error: 1 (1*2*1=2) 2 (2*1*2=4) 4? No, loop runs 1..line.
    // i=1: print 1. C = 1 * (3-1) * 1 = 2.
    // i=2: print 2. C = 2 * (3-2) * 2 = 4.
    // i=3: print 4.
    // Output: 1 2 4 instead of 1 2 1.
    printPascalsTriangle(5);
    return 0;
}
