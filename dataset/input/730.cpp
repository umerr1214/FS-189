#include <iostream>
using namespace std;

// Robustness: Fixed size arrays in signature imply non-null (usually stack allocated),
// but they can be passed as pointers.
// `int data[][6]` is `int (*data)[6]`. It CAN be NULL.

bool Exists(int data[][6], int pattern[][3]) {
    // Robustness Issue: No NULL check.
    
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            bool match = true;
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    if (data[i + r][j + c] != pattern[r][c]) { // Crash if data or pattern is NULL
                        match = false;
                        break;
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
    // Exists(NULL, NULL); // Crash
    return 0;
}
