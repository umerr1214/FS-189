#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void upperCase(char array[]) {
    int len = strlen(array);
    for (int i = 0; i < len; i++) {
        // Logical Error: Only capitalizes the start of the word, forgetting the end of the word.
        // Or incorrect condition for end of word.
        
        if (i == 0 || array[i - 1] == ' ') {
            array[i] = toupper(array[i]);
        }
        // Missing the check for end of word (array[i+1] == ' ' || i == len-1)
    }
}

int main() {
    char arr[100] = "hello world";
    cout << "Before: " << arr << endl;
    
    // Expected: "HellO WorlD"
    // Actual: "Hello World"
    upperCase(arr);
    
    cout << "After: " << arr << endl;
    return 0;
}
