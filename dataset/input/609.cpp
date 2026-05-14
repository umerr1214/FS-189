#include <iostream>
using namespace std;

int searchData(int arr[], int size, int key) {
    // Semantic Error: Confusing array index with array value
    for (int i = 0; i < size; i++) {
        // Checking if the index 'i' is equal to the key, not the value at arr[i]
        if (i == key) { 
            return arr[i]; // Returning the value instead of the index
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 2; // Searching for key '2'
    
    int result = searchData(arr, size, key);
    
    // This will print "Element found: 30" because index 2 matches key 2
    cout << "Result: " << result << endl;
    
    return 0;
}
