#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(int arr[], int n) {
    // Efficiency/Readability:
    // Selection sort is O(N^2).
    // Using `std::sort` (QuickSort/IntroSort) is O(N log N).
    // For sorting, using O(N^2) algorithms is generally an efficiency issue unless N is small.
    // But the question asks for Selection Sort specifically.
    
    // Let's introduce an efficiency issue specific to Selection Sort implementation.
    // e.g. Creating a new array to find min?
    // Or swapping in the inner loop (making it Bubble Sort-ish but worse)?
    // If we swap EVERY time `arr[j] < arr[i]` in inner loop, it works but does more writes.
    // That's actually just unoptimized sort.
    
    // Let's assume the question allows any sort but asks for Selection Sort, 
    // and I implement Bubble Sort (O(N^2)) but call it Selection Sort? 
    // That's a logical error.
    
    // Let's stick to the "uses unnecessary memory" pattern.
    // Converting to vector, sorting, copying back?
    
    vector<int> v(arr, arr + n);
    // Naive Selection Sort on vector
    for (int i = 0; i < n; i++) {
        int minVal = v[i];
        int minIdx = i;
        for (int j = i; j < n; j++) {
             if (v[j] < minVal) {
                 minVal = v[j];
                 minIdx = j;
             }
        }
        swap(v[i], v[minIdx]);
    }
    
    for (int i = 0; i < n; i++) arr[i] = v[i];
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    selectionSort(arr, 5);
    return 0;
}
