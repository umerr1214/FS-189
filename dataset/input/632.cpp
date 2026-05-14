#include <iostream>
#include <vector>
using namespace std;

void CheckFrequency(int arr[], int size) {
    vector<bool> visited(size, false);
    
    for (int i = 0; i < size; i++) {
        // Logical Error: Missing check if already visited
        // if (visited[i] == true) continue; // This line is missing or commented out
        
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
    int arr[] = {10, 20, 20, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Will print:
    // 10 occurs 2 times
    // 20 occurs 2 times
    // 20 occurs 1 times (Duplicate print!)
    // 10 occurs 1 times (Duplicate print!)
    CheckFrequency(arr, size);
    
    return 0;
}
