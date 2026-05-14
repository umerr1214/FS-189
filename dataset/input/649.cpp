#include <iostream>
using namespace std;

void findMissingElements(const int arr1[], int size1, const int arr2[], int size2, int result[], int& resultSize) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i];
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    while (i < size1) {
        result[k++] = arr1[i];
        i++;
    }
    resultSize = k
} // Syntax Error: Missing semicolon

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
