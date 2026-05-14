#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

void sortData(int arr[], int size, char choice) {
    if (arr == nullptr || size <= 0) {
        return;
    }

    if (choice == 'a') {
        std::sort(arr, arr + size);
    } else if (choice == 'd') {
        std::sort(arr, arr + size, std::greater<int>());
    } else {
        // Handle invalid choice? For now, do nothing or default to ascending
        // Let's assume strict requirement: do nothing if invalid
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    sortData(arr, size, 'a');
    
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    sortData(arr, size, 'd');
     for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
