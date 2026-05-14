#include <iostream>
using namespace std;

void sortData(int arr[], int size, char choice) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Logical Error: Swapped logic for 'a' and 'd'
            // 'a' should be ascending ( > ), 'd' should be descending ( < )
            // Here 'a' checks < so it pushes smaller elements to the end (descending)
            if (choice == 'a') {
                if (arr[j] < arr[j + 1]) { 
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            } else if (choice == 'd') {
                if (arr[j] > arr[j + 1]) {
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
    
    // Intention: Ascending. Result: Descending
    sortData(arr, size, 'a');
    
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
