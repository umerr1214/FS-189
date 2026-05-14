#include <iostream>
#include <string>
using namespace std;

void lookupName(const string& target, const string names[], const string numbers[], int size) {
    if (names == nullptr || numbers == nullptr || size < 0) {
        cout << "Invalid input." << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (names[i] == target) {
            cout << "Phone number: " << numbers[i] << endl;
            found = true;
            break; // Stop after finding the first match
        }
    }
    
    if (!found) {
        cout << "Name not found." << endl;
    }
}

int main() {
    string names[] = {"Michael Myers", "Ash Williams", "Jack Torrance", "Freddy Krueger"};
    string numbers[] = {"333-8000", "333-2323", "333-6128", "333-9432"};
    int size = 4;
    
    lookupName("Ash Williams", names, numbers, size);
    lookupName("Jason Voorhees", names, numbers, size);
    lookupName("Test", nullptr, nullptr, 0);
    
    return 0;
}
