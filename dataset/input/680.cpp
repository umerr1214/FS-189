#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void removeDuplicates(char arr[]) {
    int n = strlen(arr);
    
    // Logical Error: Fails to update the null terminator, leaving garbage characters at the end.
    // Also, logic might be slightly off if we just skip duplicates but don't compact the array.
    // Let's implement compacting logic but forget the null terminator.
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (j == i) {
            arr[index++] = arr[i];
        }
    }
    // Missing: arr[index] = '\0';
}

int main() {
    char arr[] = "programming";
    // Expected: "progamin" (length 8)
    // Actual: "progaminming" (garbage at end because null terminator not moved)
    removeDuplicates(arr);
    
    cout << "Unique characters: " << arr << endl;
    return 0;
}
