#include <iostream>
#include <vector>

using namespace std;

int main() {
    int arr[5]; // Array of size 5, valid indices 0-4

    cout << "Enter 5 integers:" << endl;
    // Semantic Error: Loop goes out of bounds, trying to write to arr[5]
    for (int i = 0; i <= 5; ++i) { // Loop condition should be i < 5
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i]; // When i is 5, this attempts to write to arr[5], which is out of bounds.
    }

    cout << "Array elements in reverse order:" << endl;
    for (int i = 4; i >= 0; --i) {
        cout << arr[i] << endl;
    }

    return 0;
}