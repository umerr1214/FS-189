#include <iostream>
using namespace std;

bool Exists(int data[][6], int pattern[][3]) {
    // Logical Error: Incorrect loop bounds for searching
    // Should be i <= 6-3 (3), but let's iterate too far or not enough
    // Or maybe matching logic error.
    
    // Let's use incorrect loop logic for inner matching.
    for (int i = 0; i < 6; i++) { // Going out of bounds potentially if we access i+r, but logic error is simpler
        for (int j = 0; j < 6; j++) {
            bool match = true;
            // Only checking the first element of the pattern?
            if (data[i][j] != pattern[0][0]) {
                match = false;
            }
            // If first element matches, we return true immediately without checking the rest
            if (match) return true; 
        }
    }
    return false;
}

int main() {
    int data[6][6] = {
        {1, 2, 7, 8, 9, 6}, // Has '3' at index 2? No.
        {2, 2, 3, 4, 5, 6}, // Has '3' at index 2.
        {3, 2, 3, 4, 5, 6},
        {4, 2, 3, 4, 5, 6},
        {5, 2, 9, 8, 7, 6},
        {6, 2, 7, 4, 5, 6}
    };
    int pattern[3][3] = {
        {3, 4, 5},
        {3, 4, 5},
        {3, 4, 5}
    };
    
    // Expected: True (found 3x3 block)
    // Actual: True (found '3' at data[1][2]), but it returns true even if the block doesn't match
    // E.g. if pattern was {{3,0,0}...}, it would still return true because it only checks [0][0].
    
    if (Exists(data, pattern)) {
        cout << "Pattern found!" << endl;
    } else {
        cout << "Pattern not found." << endl;
    }
    return 0;
}
