#include <iostream>
using namespace std;

void evenSort(int arr[], int size) {
    int j = -1;
    for (int i = 0; i < size; i++) {
        // Semantic Error: checking if arr[i] is odd using bitwise incorrectly or confusing return values
        // or simply using assignment in condition
        if (arr[i] % 2 == 0) { // If even
            j++;
            // Swap arr[i] and arr[j]
            // Semantic error: Using bitwise XOR swap incorrectly on same variable if i==j
            // which sets it to 0. 
            if (i != j) {
                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];
            } else {
                // If i == j, XOR swap fails (sets to 0) if we didn't check i!=j
                // Let's force the error by removing the check or doing something else semantic.
                // Let's try a different semantic error:
                // Treating array value as index
                arr[j] = arr[arr[i]]; // Semantic misuse: using value as index
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    evenSort(arr, size);
    
    cout << "Array after segregation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
