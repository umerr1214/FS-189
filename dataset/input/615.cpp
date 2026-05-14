#include <iostream>
using namespace std;

void sortData(int arr[], int size, char choice) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (choice = 'a') { // Semantic Error: using assignment '=' instead of comparison '=='
                // This condition is always true (ascii of 'a' is non-zero)
                // So it always sorts ascending, ignoring 'd'
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            } else if (choice == 'd') {
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
    
    // User wants descending, but gets ascending due to assignment in if condition
    sortData(arr, size, 'd');
    
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
