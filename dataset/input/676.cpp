#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void reverseWords(char arr[]) {
    // Robustness Issue: No NULL check.
    // strlen(NULL) crashes.
    
    int n = strlen(arr);
    reverse(arr, arr + n);
    
    int start = 0;
    for (int end = 0; end < n; end++) {
        if (arr[end] == ' ') {
            reverse(arr + start, arr + end);
            start = end + 1;
        }
    }
    reverse(arr + start, arr + n);
}

int main() {
    char* arr = NULL;
    // Crash
    // reverseWords(arr);
    return 0;
}
