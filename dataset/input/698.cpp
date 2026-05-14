#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void capitalizeWords(char arr[]) {
    bool newWord = true;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (isspace(arr[i])) {
            newWord = true;
        } else if (newWord) {
            // Logical Error: Forgetting to set newWord to false
            // This causes ALL characters to be uppercased if they follow a space,
            // but since newWord stays true, every subsequent character is also treated as start of word
            // if we didn't have the 'else' block correctly structured or simply reset flag wrong.
            
            // Actually, if newWord remains true, then every character enters this block
            // and gets uppercased.
            arr[i] = toupper(arr[i]);
            // newWord = false; // Missing this line
        } else {
            arr[i] = tolower(arr[i]);
        }
    }
}

int main() {
    char arr[] = "hello world";
    // Expected: "Hello World"
    // Actual: "HELLO WORLD" (because newWord never becomes false)
    capitalizeWords(arr);
    cout << "Capitalized: " << arr << endl;
    return 0;
}
