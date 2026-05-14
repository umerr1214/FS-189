#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

const int ROWS = 3;
const int COLS = 10;

void characterHistogram(char grid[][COLS], int rows) {
    // Efficiency/Readability:
    // Using a map<char, int> is readable but slightly less efficient than int[256] (O(N log K) vs O(N)).
    // But iterating multiple times or doing something redundant is better for this category.
    // Let's sort the characters first? O(N log N) just to count?
    
    vector<char> chars;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] != '\0') {
                chars.push_back(grid[i][j]);
            }
        }
    }
    
    // Inefficient: iterating vector for each unique char count
    for (int i = 0; i < 256; i++) {
        char target = (char)i;
        int count = 0;
        for (char c : chars) {
            if (c == target) count++;
        }
        if (count > 0) {
            cout << target << ": ";
            for (int k = 0; k < count; k++) cout << "*";
            cout << endl;
        }
    }
}

int main() {
    char grid[ROWS][COLS] = {
        "hello",
        "world",
        "test"
    };
    characterHistogram(grid, ROWS);
    return 0;
}
