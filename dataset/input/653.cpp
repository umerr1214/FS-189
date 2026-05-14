#include <iostream>
using namespace std;

void findMissingElements(const int arr1[], int size1, const int arr2[], int size2, int result[], int& resultSize) {
    // Efficiency Issue: O(N*M) approach
    // Since arrays are sorted, we should use O(N+M) two pointer.
    // But here we implement a nested loop checking "exists in arr2" for every element of arr1.
    // This ignores the sorted property and is inefficient.
    
    int k = 0;
    for (int i = 0; i < size1; i++) {
        bool found = false;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[k++] = arr1[i];
        }
    }
    resultSize = k;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 4};
    int result[10];
    int resultSize = 0;
    
    findMissingElements(arr1, 5, arr2, 2, result, resultSize);
    
    cout << "Missing Elements: ";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
