#include <iostream>
#include <climits>
using namespace std;

void findMinMax(int arr[], int &min, int &max, int size) {
    // Semantic Error: Assuming arr is just a pointer and trying to treat it like a single int value in logic or misusing types
    // Here, let's mistakenly assign the pointer address to min instead of value, or swap them
    
    int* ptr = arr;
    min = (int)ptr; // Semantic/Type misuse: Assigning address to int reference intended for value
    max = size; 
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
             // Logic that doesn't make sense with the bad initialization
             min = arr[i]; 
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
