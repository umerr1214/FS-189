#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void findMinMax(int arr[], int &min, int &max, int size) {
    // Readability/Efficiency Issue: Sorting the array to find min/max
    // This is O(N log N) instead of O(N)
    
    if (size <= 0) return;

    // Inefficient approach: sorting just to get ends
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    min = arr[0];
    max = arr[size-1];
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
