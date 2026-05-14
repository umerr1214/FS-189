#include <iostream>
using namespace std;

void printPascalsTriangle(int n) {
    for (int line = 1; line <= n; line++) {
        int C = 1;
        for (int i = 1; i <= line; i++) {
            cout << C << " ";
            // Semantic Error: Integer division losing precision or order of operations issue?
            // (line - i) / i * C ?
            // No, that's logical.
            
            // Let's use assignment in array index? No array here.
            
            // Let's use bitwise shift instead of division?
            // C = C * (line - i) >> i; // Semantically different from division for non-powers of 2
            
            // Let's use string literal address?
            // cout << C + " "; // Adding int to string pointer -> advances pointer
            
            // Let's use:
            C = C * ((line - i) / i); // Semantic/Logic: Integer division happens BEFORE multiplication.
            // (line - i) / i will be 0 if i > line/2 approx.
            // E.g. line=5, i=3. (2)/3 = 0. C becomes 0.
            // Correct is (C * (line-i)) / i.
            // This is arguably logical, but often classified as semantic understanding of operator precedence/types.
        }
        cout << endl;
    }
}

int main() {
    // Expected Row 5: 1 4 6 4 1
    // Actual: 
    // i=1: 1. C = 1 * (4/1) = 4.
    // i=2: 4. C = 4 * (3/2) = 4 * 1 = 4. (Should be 6)
    // i=3: 4. C = 4 * (2/3) = 0.
    // i=4: 0.
    // Output: 1 4 4 0 0
    printPascalsTriangle(5);
    return 0;
}
