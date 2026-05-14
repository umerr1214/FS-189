#include <iostream>
using namespace std;

void findMissingElements(const int arr1[], int size1, const int arr2[], int size2, int result[], int& resultSize) {
    if (arr1 == nullptr && size1 > 0) return; // Error or assume empty?
    // If result is null, we can't write. 
    if (result == nullptr) {
        resultSize = 0;
        return;
    }

    // Two pointer approach O(N + M)
    int i = 0, j = 0, k = 0;
    
    // Handle potential nullptrs for inputs if sizes are 0
    // If arr2 is null/empty, all arr1 goes to result
    if (arr2 == nullptr || size2 <= 0) {
        if (arr1 != nullptr) {
            for (int x = 0; x < size1; x++) result[k++] = arr1[x];
        }
        resultSize = k;
        return;
    }
    if (arr1 == nullptr || size1 <= 0) {
        resultSize = 0;
        return;
    }

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i];
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            // Equal: skip both
            i++;
            j++;
        }
    }
    
    // Add remaining elements from arr1
    while (i < size1) {
        result[k++] = arr1[i];
        i++;
    }
    
    resultSize = k;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 10, 12};
    int arr2[] = {2, 4, 10};
    int result[20];
    int resultSize = 0;
    
    findMissingElements(arr1, 7, arr2, 3, result, resultSize);
    
    cout << "Missing Elements: ";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
