#include <iostream>
#include <vector>
using namespace std;

void evenSort(int arr[], int size) {
    vector<int> evens;
    vector<int> odds;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evens.push_back(arr[i]);
        } else {
            odds.push_back(arr[i]);
        }
    }
    
    int index = 0;
    for (int x : evens) {
        arr[index++] = x;
    }
    for (int x : odds) {
        arr[index++] = x
    } // Syntax Error: Missing semicolon
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    evenSort(arr, size);
    
    cout << "Array after segregation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
