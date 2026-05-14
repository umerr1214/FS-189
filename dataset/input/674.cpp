#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void reverseWords(char arr[]) {
    int n = strlen(arr);
    
    // Logical Error: Only reversing individual words but NOT reversing the whole string first (or vice versa).
    // This results in words being reversed in place, but their order remaining the same.
    // e.g., "Hello World" -> "olleH dlroW" instead of "World Hello"
    
    int start = 0;
    for (int end = 0; end < n; end++) {
        if (arr[end] == ' ') {
            reverse(arr + start, arr + end);
            start = end + 1;
        }
    }
    reverse(arr + start, arr + n);
    
    // Missing step: reverse(arr, arr + n);
}

int main() {
    char arr[] = "Hello World";
    // Expected: "World Hello"
    // Actual: "olleH dlroW"
    reverseWords(arr);
    
    cout << "Reversed: " << arr << endl;
    return 0;
}
