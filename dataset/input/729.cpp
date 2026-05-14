#include <iostream>
using namespace std;

bool Exists(int data[][6], int pattern[][3]) {
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            bool match = true;
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    // Semantic Error: Accessing 2D array using single index arithmetic incorrectly?
                    // Or confusing row/col?
                    
                    // Let's use bitwise OR instead of logical OR/equality check?
                    // if (data[i+r][j+c] | pattern[r][c]) ... checks if either is non-zero
                    
                    // Let's use assignment in condition again? Classic.
                    if (data[i+r][j+c] = pattern[r][c]) { // Assignment: Modifies data!
                        // And returns true if pattern value is non-zero.
                        // If pattern value is 0, it thinks it's a mismatch (false).
                        // If pattern is non-zero, it thinks it's a MATCH? 
                        // Wait, if (cond) -> true means "mismatch found" or "match continued"?
                        // Usually: if (data != pattern) { match = false; break; }
                        // Here: if (data = pattern) -> true (match?), then what?
                        // We need the reverse logic for the error to be interesting.
                        
                        // Let's just say "mismatch logic" is flipped or misused.
                        
                        // Let's use a pointer semantic error.
                        // Treating int as a pointer?
                        // *(data + i + r) + j + c ... 
                        
                        // Let's confuse the pointers.
                        // data[i+r] is int*. pattern[r] is int*.
                        // comparing pointers?
                        if (data[i+r] == pattern[r]) { // Comparing row addresses? Always false.
                             match = false;
                             break;
                        }
                    }
                }
                if (!match) break;
            }
            if (match) return true;
        }
    }
    return false;
}

int main() {
    int data[6][6] = {{0}};
    int pattern[3][3] = {{0}};
    
    // Expected: True (all zeros match)
    // Actual: Depends on logic.
    // data[i+r] == pattern[r] compares addresses of rows.
    // They are different arrays, so always false.
    // So `if` condition is false. loop continues. match remains true.
    // Returns true immediately?
    // Wait, if condition `if (address == address)` is false, it does NOT set match=false.
    // So match stays true.
    // So it returns true for ANY input?
    
    if (Exists(data, pattern)) {
        cout << "Pattern found!" << endl;
    } else {
        cout << "Pattern not found." << endl;
    }
    return 0;
}
