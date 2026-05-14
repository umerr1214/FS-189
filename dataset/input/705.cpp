#include <iostream>
#include <vector>
using namespace std;

const int COLS = 3;

void findUniqueElements(int arr[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            // Semantic Error: Using 2D array indices as 1D arithmetic without proper stride?
            // Or trying to access it like a pointer incorrectly.
            
            // Let's try: arr[i * COLS + j] 
            // This is valid if 'arr' was int*, but 'arr' is int[][COLS].
            // arr[x] returns a row pointer (int*). 
            // So arr[i * COLS + j] returns a row pointer (pointer arithmetic on arrays of arrays).
            // Then we try to compare it with int?
            
            // Let's simplify:
            // Treating array value as pointer/address?
            // Or using assignment operator in loop?
            
            // Let's assume user tries to treat 2D array as 1D array directly:
            // if (arr[i] == arr[j]) -> comparing row pointers addresses?
            
            int val = arr[i][j];
            // ... check for duplicates ...
            bool isUnique = true;
            for(int k=0; k<rows*COLS; k++) {
                 // Semantic error: accessing 2D array as 1D via single index
                 // arr[k] is int*, not int.
                 // Comparing int (val) with int* (arr[k])
                 if (val == (long long)arr[k]) { // Forced cast to make it compile but semantic garbage
                     if (k != (i*COLS + j)) {
                         isUnique = false;
                         break;
                     }
                 }
            }
            if (isUnique) cout << val << " ";
        }
    }
    cout << endl;
}

int main() {
    int arr[3][COLS] = {{1, 2, 1}, {3, 4, 2}, {5, 6, 5}};
    findUniqueElements(arr, 3);
    return 0;
}
