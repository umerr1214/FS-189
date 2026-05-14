#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void convertStartEndToUpper(char arr[]) {
    if (arr == nullptr) return;

    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        // Must be a letter to capitalize
        if (isalpha(arr[i])) {
            // Start of word: index 0 or previous char is space
            bool isStart = (i == 0 || arr[i - 1] == ' ');
            
            // End of word: last index or next char is space
            bool isEnd = (i == len - 1 || arr[i + 1] == ' ');
            
            if (isStart || isEnd) {
                arr[i] = toupper(arr[i]);
            }
        }
    }
}

int main() {
    char arr1[100] = "hello world example";
    cout << "Before: " << arr1 << endl;
    convertStartEndToUpper(arr1);
    cout << "After: " << arr1 << endl;
    
    char arr2[100] = "a";
    convertStartEndToUpper(arr2);
    cout << "After: " << arr2 << endl; // "A"

    char arr3[100] = "  test  ";
    convertStartEndToUpper(arr3);
    cout << "After: '" << arr3 << "'" << endl; // "  TesT  "
    
    convertStartEndToUpper(NULL);
    
    return 0;
}
