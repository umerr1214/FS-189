#include <iostream>
using namespace std;

void sortData(int arr[], int size, char choice) {
    // Readability/Efficiency Issue: Bubble sort is O(N^2)
    // Also, nested if-else structure inside the inner loop is slightly inefficient/repetitive
    // It checks 'choice' O(N^2) times.
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (choice == 'a') {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            } else { // Assuming anything else is descending or checking 'd'
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    sortData(arr, size, 'a');
    
    return 0;
}
