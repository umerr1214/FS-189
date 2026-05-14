#include <iostream>
using namespace std;

void binomSum(int arr[], int size) {
    if (arr == nullptr || size <= 0) {
        return;
    }

    for (int i = 0; i < size; i++) {
        int n = arr[i];
        if (n <= 0) {
            arr[i] = 0;
        } else {
            // Use long long to prevent overflow during multiplication
            long long sum = (static_cast<long long>(n) * (n + 1)) / 2;
            arr[i] = static_cast<int>(sum);
        }
    }
}

int main() {
    int arr[] = {6, 4, 1, 3, 0, -5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    binomSum(arr, size);
    
    cout << "Output Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
