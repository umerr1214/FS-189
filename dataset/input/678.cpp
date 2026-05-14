#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void reverseWords(char arr[]) {
    if (arr == nullptr) return;
    
    int n = strlen(arr);
    if (n == 0) return;
    
    // Step 1: Reverse the whole string
    // "Hello World" -> "dlroW olleH"
    reverse(arr, arr + n);
    
    // Step 2: Reverse each word individually
    // "dlroW" -> "World", "olleH" -> "Hello"
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
    char arr1[] = "Hello World";
    reverseWords(arr1);
    cout << "Reversed: " << arr1 << endl;
    
    char arr2[] = "One";
    reverseWords(arr2);
    cout << "Reversed: " << arr2 << endl;

    char arr3[] = "  Space  Test  ";
    // Note: Standard "reverse words" usually preserves spaces or collapses them.
    // This in-place reversal preserves all spaces.
    // "  Space  Test  " -> "  tseT  ecapS  " (reversed chars)
    // Then reverse words: "  Test  Space  "
    reverseWords(arr3);
    cout << "Reversed: '" << arr3 << "'" << endl;
    
    return 0;
}
