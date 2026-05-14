#include <iostream>

int main() {
    int size;
    cout << "Enter the desired size of the array: "; // Syntax Error: Missing std::
    cin >> size; // Syntax Error: Missing std::

    if (size <= 0) {
        cout << "Array size must be positive." << endl; // Syntax Error: Missing std::
        return 1;
    }

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }

    cout << "Array elements: "; // Syntax Error: Missing std::
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " "; // Syntax Error: Missing std::
    }
    cout << endl; // Syntax Error: Missing std::

    delete[] arr;
    arr = nullptr;

    return 0;
}