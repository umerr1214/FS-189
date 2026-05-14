#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void removeDuplicates(char arr[]) {
    if (arr == nullptr) return;
    
    // Use a boolean map for O(1) space (256 constant) and O(N) time
    bool seen[256] = {false}; 
    int index = 0;
    
    for (int i = 0; arr[i] != '\0'; i++) {
        unsigned char c = (unsigned char)arr[i];
        if (!seen[c]) {
            seen[c] = true;
            arr[index++] = arr[i];
        }
    }
    arr[index] = '\0';
}

int main() {
    char arr1[] = "programming";
    removeDuplicates(arr1);
    cout << "Unique: " << arr1 << endl;
    
    char arr2[] = "aaaa";
    removeDuplicates(arr2);
    cout << "Unique: " << arr2 << endl;

    removeDuplicates(NULL); // Should not crash
    
    return 0;
}
