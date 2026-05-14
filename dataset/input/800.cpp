#include <iostream>
using namespace std;

void mergeArrays(const int arr1[], int n1, const int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    // Logical Error: Forgetting to copy remaining elements from one of the arrays.
    // e.g. If arr1 finishes first, we copy arr2. But if arr2 finishes first, we forget arr1?
    // Or just forgetting both loops.
    
    // Only copying tail of arr1, forgetting arr2's tail if arr1 finishes first.
    while (i < n1) {
        result[k++] = arr1[i++];
    }
    // Missing: while (j < n2) ...
}

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6, 8, 10}; // arr2 is longer
    int result[8] = {0};
    
    // arr1 will finish (1,2,3,4,5 used). 6,8,10 remain in arr2.
    // They won't be copied.
    mergeArrays(arr1, 3, arr2, 5, result);
    
    cout << "Merged Array: ";
    for (int i = 0; i < 8; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
