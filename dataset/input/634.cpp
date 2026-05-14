#include <iostream>
#include <vector>
using namespace std;

void CheckFrequency(int arr[], int size) {
    // Robustness Issue: No null pointer check or empty size handling
    // If arr is NULL, accessing arr[i] causes segfault.
    
    vector<bool> visited(size, false); // If size is huge/negative, this might throw or crash
    
    for (int i = 0; i < size; i++) {
        if (visited[i] == true) {
            continue;
        }
        
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) { // Crash if arr is NULL
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " occurs " << count << " times" << endl;
    }
}

int main() {
    int* arr = NULL;
    // CheckFrequency(arr, 5); // Crash
    return 0;
}
