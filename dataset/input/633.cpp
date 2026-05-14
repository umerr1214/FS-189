#include <iostream>
#include <vector>
using namespace std;

void CheckFrequency(int arr[], int size) {
    vector<bool> visited(size, false);
    
    for (int i = 0; i < size; i++) {
        if (visited[i] == true) {
            continue;
        }
        
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            // Semantic Error: Comparing addresses instead of values? 
            // Or using assignment in if condition?
            // Let's use assignment in if condition again as it's a common semantic error
            // or perhaps comparing index 'i' with 'arr[j]'?
            
            if (arr[i] = arr[j]) { // Semantic Error: Assignment instead of comparison
                // This modifies arr[i] to be arr[j] and returns true if arr[j] != 0
                // So it counts almost everything as a match and corrupts the array
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " occurs " << count << " times" << endl;
    }
}

int main() {
    int arr[] = {10, 20, 20, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    CheckFrequency(arr, size);
    
    return 0;
}
