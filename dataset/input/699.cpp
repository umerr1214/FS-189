#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void capitalizeWords(char arr[]) {
    bool newWord = true;
    for (int i = 0; arr[i] != '\0'; i++) {
        // Semantic Error: Assigning integer value 'true' to character array?
        // Or using bitwise operators incorrectly on bools?
        
        // Let's confuse character assignment.
        if (isspace(arr[i])) {
            newWord = true;
        } else if (newWord) {
            // Semantic Error: Assigning the address of the toupper function to the char?
            // arr[i] = toupper; // Error: invalid conversion
            
            // Let's use assignment in condition again? No, used that a lot.
            // Let's try incorrect type cast or using sizeof incorrectly.
            
            // How about using 'newWord' as the character value?
            arr[i] = newWord; // Sets character to ASCII 1 (SOH)
            newWord = false;
        } else {
            arr[i] = tolower(arr[i]);
        }
    }
}

int main() {
    char arr[] = "hello";
    capitalizeWords(arr);
    // arr[0] becomes char(1)
    cout << "Capitalized: " << arr << endl;
    return 0;
}
