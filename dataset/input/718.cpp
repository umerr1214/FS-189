#include <iostream>
#include <string>
using namespace std;

void lookupName(string target, string names[], string numbers[], int size) {
    // Robustness Issue: No check for negative size.
    // If size is negative, loop condition i < size fails immediately (good)
    // BUT what if names or numbers are NULL?
    // C++ arrays passed as pointers. string names[] decays to string*.
    // If passed NULL, crash.
    
    if (size < 0) return; // Partial check
    // Missing: if (names == nullptr || numbers == nullptr) return;
    
    // Crash here if names is NULL
    for (int i = 0; i < size; i++) {
        if (names[i] == target) {
            cout << "Phone number: " << numbers[i] << endl;
            return;
        }
    }
    cout << "Name not found." << endl;
}

int main() {
    string* names = nullptr;
    string* numbers = nullptr;
    
    // Crash
    // lookupName("Target", names, numbers, 5);
    
    return 0;
}
