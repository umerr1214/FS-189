#include <iostream>
#include <map>
using namespace std;

void CheckFrequency(int arr[], int size) {
    if (arr == nullptr || size <= 0) {
        return;
    }

    map<int, int> frequencyMap;
    
    for (int i = 0; i < size; i++) {
        frequencyMap[arr[i]]++;
    }
    
    for (auto const& [key, val] : frequencyMap) {
        cout << key << " occurs " << val << " times" << endl;
    }
}

int main() {
    int arr[] = {10, 20, 20, 10, 10, 20, 5, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    CheckFrequency(arr, size);
    
    int* empty = NULL;
    CheckFrequency(empty, 0); // Should handle gracefully
    
    return 0;
}
