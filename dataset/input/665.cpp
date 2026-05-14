#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void findDuplicateCharacters(const char arr[], char duplicates[], int& duplicatesSize) {
    // Efficiency Issue: O(N^3)
    // Outer loops O(N^2), inner check 'alreadyAdded' takes O(N) (or O(number of duplicates)).
    // Total O(N^3).
    // Can be done in O(N) using frequency map/array.
    
    int k = 0;
    int len = strlen(arr);
    
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                bool alreadyAdded = false;
                for (int m = 0; m < k; m++) {
                    if (duplicates[m] == arr[i]) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    duplicates[k++] = arr[i];
                }
            }
        }
    }
    duplicatesSize = k;
}

int main() {
    const char arr[] = "programming";
    char duplicates[20];
    int duplicatesSize = 0;
    
    findDuplicateCharacters(arr, duplicates, duplicatesSize);
    
    cout << "Duplicates: ";
    for (int i = 0; i < duplicatesSize; i++) {
        cout << duplicates[i] << " ";
    }
    cout << endl;
    return 0;
}
