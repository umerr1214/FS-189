#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

bool searchWord(char grid[][COLS], const char* word) {
    // Efficiency/Readability:
    // Extracting every possible string from the grid into a list and searching the list?
    // Very inefficient memory usage and time O(N^3) or worse.
    
    vector<string> allSubstrings;
    
    // Generate all horizontal substrings
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            string s = "";
            for(int k=j; k<COLS; k++) {
                s += grid[i][k];
                allSubstrings.push_back(s);
            }
        }
    }
    // ... vertical ... diagonal ...
    
    string target = word;
    for(const string& s : allSubstrings) {
        if (s == target) return true;
    }
    return false;
}

int main() {
    return 0;
}
