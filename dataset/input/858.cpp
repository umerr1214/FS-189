#include <iostream>
using namespace std;

void printPascalsTriangle(int n) {
    if (n <= 0) return;

    for (int line = 1; line <= n; line++) {
        // Use long long to prevent overflow for larger n
        long long C = 1;
        for (int i = 1; i <= line; i++) {
            cout << C << " ";
            // Update C to the next coefficient
            // C(line, i) = C(line, i-1) * (line - i + 1) / i
            // Wait, my loop i is 1-based, matching term index.
            // Current C is C(line-1, i-1).
            // Next should be C(line-1, i).
            // Formula: C_next = C_curr * (N - K) / (K + 1) where N is row index (0-based) and K is term index.
            // Here 'line' is 1-based. So row index is line-1.
            // Term index is i-1.
            // C_next = C * ((line-1) - (i-1)) / ((i-1) + 1)
            // C_next = C * (line - i) / i.
            // This assumes we print C BEFORE update. Yes.
            // And use long long arithmetic.
            
            C = C * (line - i) / i;
        }
        cout << endl;
    }
}

int main() {
    printPascalsTriangle(5);
    // Robustness test for overflow range (still might overflow valid long long eventually but much better than int)
    printPascalsTriangle(10); 
    printPascalsTriangle(0);
    return 0;
}
