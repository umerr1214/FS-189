#include <iostream>
using namespace std;

void mergeArrays(const int arr1[], int n1, const int arr2[], int n2, int result[]) {
    if ((arr1 == nullptr && n1 > 0) || (arr2 == nullptr && n2 > 0) || result == nullptr) {
        return; 
    }
    
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    while (i < n1) {
        result[k++] = arr1[i++];
    }
    
    while (j < n2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int result[8];
    
    mergeArrays(arr1, 4, arr2, 4, result);
    
    cout << "Merged Array: ";
    for (int i = 0; i < 8; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    mergeArrays(NULL, 0, NULL, 0, result); // Robustness
    
    return 0;
}
