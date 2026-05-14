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
    
    CheckFrequency(arr, size) // Syntax Error: missing semicolon
    
    return 0;
}
