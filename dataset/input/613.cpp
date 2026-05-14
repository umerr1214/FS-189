#include <iostream>
using namespace std;

void sortData(int arr[], int size, char choice) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (choice == 'a') {
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
} // Missing semicolon if this were a class method, but fine here. Let's add a syntax error elsewhere.

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    sortData(arr, size, 'a');
    
    for (int i = 0; i < size; i++)
        cout << arr[i] << " "
    cout << endl; // Syntax error: missing semicolon on previous line
    
    return 0;
}
