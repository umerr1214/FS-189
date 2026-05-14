#include <iostream>
#include <climits>
using namespace std;

void findMinMax(int arr[], int &min, int &max, int size) {
    min = INT_MAX
    max = INT_MIN; // Syntax error: missing semicolon
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
}

int main() {
    int arr[] = {10, 2, 5, 8, 1, 9};
    int min, max;
    int size = sizeof(arr) / sizeof(arr[0]);
    
    findMinMax(arr, min, max, size);
    
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    
    return 0;
}
