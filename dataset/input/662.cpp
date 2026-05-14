#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void findDuplicateCharacters(const char arr[], char duplicates[], int& duplicatesSize) {
    int k = 0;
    int len = strlen(arr);
    
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                // Logical Error: Failing to check if the duplicate is already added to the result array.
                // This results in the same duplicate character appearing multiple times in the output.
                // e.g., 'programming' -> 'r', 'g', 'm' but maybe 'r' again if it appeared 3 times?
                // Actually if a char appears 3 times, say 'aaa', i=0 matches j=1 (add 'a'), j=2 (add 'a').
                duplicates[k++] = arr[i]; 
            }
        }
    }
    duplicatesSize = k;
}

int main() {
    const char arr[] = "aba";
    char duplicates[20];
    int duplicatesSize = 0;
    
    // Expected: 'a'
    // Actual: 'a' (matches index 0 and 2)
    // But for 'aaa': matches (0,1), (0,2), (1,2) -> adds 'a' 3 times!
    findDuplicateCharacters(arr, duplicates, duplicatesSize);
    
    cout << "Duplicates: ";
    for (int i = 0; i < duplicatesSize; i++) {
        cout << duplicates[i] << " ";
    }
    cout << endl;
    return 0;
}
