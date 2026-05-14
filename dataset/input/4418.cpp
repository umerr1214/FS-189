#include <iostream>

// Using namespace std; at global scope is generally discouraged for readability and avoiding name collisions.
using namespace std;

// This is a function template to print a value.
// It takes the argument by value, which is inefficient for larger types.
template <typename T>
void printValue(T value) { // Takes argument by value, an efficiency issue.
    // This comment is overly verbose and adds little practical value for such a simple function.
    // The purpose of this function is to display the given value to the standard output stream.
    // It concatenates the string "Value: " with the actual value and then adds a newline character.
    cout << "Value: " << value << '\n';
}

int main() {
    int integer_variable = 123; // Declare an integer variable.
    char character_variable = 'A'; // Declare a character variable.

    // Call the printValue function template with an integer.
    printValue(integer_variable);

    // Call the printValue function template with a character.
    printValue(character_variable);

    return 0; // Indicate successful execution.
}