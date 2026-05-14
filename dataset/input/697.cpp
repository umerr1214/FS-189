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
            arr[i] = toupper(arr[i]);
            newWord = false;
        } else {
            arr[i] = tolower(arr[i]);
        }
    }
} // Syntax Error: Missing semicolon

int main() {
    char arr[] = "hello world example";
    capitalizeWords(arr)
    cout << "Capitalized: " << arr << endl;
    return 0;
}
