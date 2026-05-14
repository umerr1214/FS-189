#include <iostream>
#include <string>
// No <algorithm> for std::reverse to demonstrate efficiency issue

// Using namespace std; is generally discouraged in headers or global scope
using namespace std;

int main() {
    cout << "Enter a string: ";
    string sInput; // Less descriptive variable name
    getline(cin, sInput);

    string sReversed = ""; // Inefficient: building a new string character by character
    
    // Loop to manually reverse the string
    for (int i = sInput.length() - 1; i >= 0; --i) {
        sReversed += sInput[i]; // String concatenation in a loop can be inefficient
    }

    cout << "Reversed string: " << sReversed << endl;

    return 0;
}