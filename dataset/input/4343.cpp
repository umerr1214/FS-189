#include <iostream>
#include <vector>

using namespace std;

int main() {
    int arr[5];

    cout << "Enter 5 integers:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Logical Error: Prints in forward order instead of reverse
    cout << "Array elements (incorrectly) in forward order:" << endl;
    for (int i = 0; i < 5; ++i) { // Loop iterates from 0 to 4, printing elements in forward order
        cout << arr[i] << endl;
    }

    return 0;
}