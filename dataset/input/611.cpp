#include <iostream>
#include <vector>
using namespace std;

int searchData(int arr[], int size, int key) {
    // Efficiency Issue: Copying array to a vector just to search
    // Allocates extra memory O(N) and takes extra time O(N) for copy
    
    vector<int> tempArr;
    for(int i = 0; i < size; i++) {
        tempArr.push_back(arr[i]);
    }
    
    for (int i = 0; i < tempArr.size(); i++) {
        if (tempArr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    
    int index = searchData(arr, size, key);
    
    cout << "Index: " << index << endl;
    
    return 0;
}
