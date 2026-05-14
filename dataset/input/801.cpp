#include <iostream>
using namespace std;

void mergeArrays(const int arr1[], int n1, const int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) {
        // Semantic Error: Using address comparison instead of value?
        // or bitwise?
        
        // Let's use assignment in condition.
        // if (arr1[i] = arr2[j])
        // Not possible because arr1 is const.
        
        // Let's use pointer arithmetic confusion.
        // arr1 + i < arr2 + j ? (Comparing addresses of elements from different arrays)
        // Syntactically valid comparison of pointers, but semantically undefined/wrong.
        
        if (&arr1[i] < &arr2[j]) { // Comparing addresses
             result[k++] = arr1[i++];
        } else {
             result[k++] = arr2[j++];
        }
    }
    
    while (i < n1) result[k++] = arr1[i++];
    while (j < n2) result[k++] = arr2[j++];
}

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int result[6];
    
    mergeArrays(arr1, 3, arr2, 3, result);
    
    // Result depends on stack layout of arr1 vs arr2.
    // Likely sorted by array chunk, not values.
    
    cout << "Merged Array: ";
    for (int i = 0; i < 6; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
