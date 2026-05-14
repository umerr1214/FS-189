#include <iostream>
using namespace std;

bool Exists(int data[][6], int pattern[][3]) {
    if (data == nullptr || pattern == nullptr) {
        return false;
    }

    // data is 6x6, pattern is 3x3
    // Iterate top-left corners of possible 3x3 subgrids in data
    // Max index for i is 6 - 3 = 3 (indices 0, 1, 2, 3)
    
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            
            // Check if pattern matches at (i, j)
            bool match = true;
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    if (data[i + r][j + c] != pattern[r][c]) {
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
    int data[6][6] = {
        {1, 2, 7, 8, 9, 6},
        {2, 2, 3, 4, 5, 6},
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
    
    if (Exists(data, pattern)) {
        cout << "Pattern found at data[1][2]" << endl;
    } else {
        cout << "Pattern not found" << endl;
    }
    
    int p2[3][3] = {{9,9,9},{9,9,9},{9,9,9}};
    if (!Exists(data, p2)) {
        cout << "Fake pattern not found correctly" << endl;
    }

    return 0;
}
