#include <iostream>
using namespace std;

void moveZeroes(int arr[], int n) {
    int count = 0; 
    
    for (int i = 0; i < n; i++) {
        // Semantic Error: Using assignment in condition?
        // if (arr[i] = 0) -> Sets arr[i] to 0, returns false.
        // Code enters else block? No, if is false.
        // So it never moves anything?
        
        // Let's use:
        // if (arr[i] == NULL) // Comparing int with NULL (valid but semantic smell if not pointer)
        
        // Let's use bitwise AND with 0? Always 0 (false).
        
        // Let's use assignment.
        if (arr[i] = 0) { // Sets current element to 0!
            // This block never executes.
        } else {
            // This block never executes either because 0 is false.
            // Wait, if (0) is false.
        }
        
        // Let's invert it.
        // if (arr[i] = 1) // Sets to 1, returns true.
        // Then we move '1' to front.
        // Effectively replaces all non-zeroes (and zeroes) with 1.
        
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }
    
    // Let's put a semantic error in the zero filling loop.
    // while (count < n) arr[count++] == 0; // Comparison statement with no effect.
    while (count < n) {
         arr[count++] == 0; // Semantic Error: Comparison with no effect instead of assignment
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    moveZeroes(arr, n);
    
    // Expected: 1 3 12 0 0
    // Actual: 1 3 12 3 12 (Garbage/duplicate at end because not cleared)
    
    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
