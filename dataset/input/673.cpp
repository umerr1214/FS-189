#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void reverseWords(char arr[]) {
    int n = strlen(arr);
    // Reverse the entire string first
    reverse(arr, arr + n);
    
    int start = 0;
    for (int end = 0; end < n; end++) {
        if (arr[end] == ' ') {
            reverse(arr + start, arr + end);
            start = end + 1;
        }
    }
    // Reverse the last word
    reverse(arr + start, arr + n);
}

int main() {
    char arr[] = "Hello World";
    cout << "Original: " << arr << endl;
    
    reverseWords(arr) // Syntax Error: Missing semicolon
    
    cout << "Reversed: " << arr << endl;
    return 0;
}
