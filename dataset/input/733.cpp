#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void upperCase(char array[]) {
    int len = strlen(array);
    for (int i = 0; i < len; i++) {
        if (i == 0 || array[i - 1] == ' ') {
            array[i] = toupper(array[i]);
        }
        if (i == len - 1 || array[i + 1] == ' ') {
            array[i] = toupper(array[i]);
        }
    }
}

int main() {
    char arr[100] = "hello world example";
    cout << "Before: " << arr << endl;
    
    upperCase(arr) // Syntax Error: Missing semicolon
    
    cout << "After: " << arr << endl;
    return 0;
}
