#include <iostream>
#include <string>
using namespace std;

void lookupName(string target, string names[], string numbers[], int size) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (names[i] == target) {
            cout << "Phone number: " << numbers[i] << endl;
            found = true;
            break;
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
    
    string target;
    cout << "Enter name to lookup: ";
    // getline(cin, target); // Commented out for automated testing
    target = "Ash Williams";
    
    lookupName(target, names, numbers, size) // Syntax Error: Missing semicolon
    
    return 0;
}
