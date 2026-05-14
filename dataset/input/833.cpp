#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(int arr[], int n) {
    // Efficiency/Readability: Creating a new array (vector) to store non-zeroes
    // then copying back.
    // This is O(N) space. Can be done in O(1) space in-place.
    
    if (arr == nullptr) return;
    
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }
    
    for (int i = 0; i < temp.size(); i++) {
        arr[i] = temp[i];
    }
    for (int i = temp.size(); i < n; i++) {
        arr[i] = 0;
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    moveZeroes(arr, n);
    for(int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
