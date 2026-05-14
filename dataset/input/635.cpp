#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void CheckFrequency(int arr[], int size) {
    // Efficiency Issue: Using nested loops O(N^2) to count frequencies
    // This works but is slow for large arrays.
    // Better approaches: Sorting O(N log N) or Hash Map O(N).
    // Here we stick to the O(N^2) approach with visited array which is common but inefficient.
    
    vector<bool> visited(size, false);
    
    for (int i = 0; i < size; i++) {
        if (visited[i] == true)
            continue;
        
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " occurs " << count << " times" << endl;
    }
}

int main() {
    int arr[] = {10, 20, 20, 10, 10, 20, 5, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    CheckFrequency(arr, size);
    
    return 0;
}
