#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int COLS = 3;

void findUniqueElements(int arr[][COLS], int rows) {
    if (rows <= 0) return;

    map<int, int> frequency;
    
    // Count frequencies O(R*C * log(unique)) or O(R*C) with unordered_map
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            frequency[arr[i][j]]++;
        }
    }
    
    // Print elements with count 1
    bool found = false;
    cout << "Unique elements: ";
    
    // To preserve order of appearance:
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (frequency[arr[i][j]] == 1) {
                cout << arr[i][j] << " ";
                found = true;
            }
        }
    }
    
    if (!found) cout << "None";
    cout << endl;
}

int main() {
    int arr[3][COLS] = {
        {1, 2, 1},
        {3, 4, 2},
        {5, 6, 5}
    };
    findUniqueElements(arr, 3);
    
    return 0;
}
