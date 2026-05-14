#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void upperCase(char array[]) {
    if (array == nullptr) return;

    int len = strlen(array);
    for (int i = 0; i < len; i++) {
        // Check if it's the first letter of a word
        // (Either start of string or preceded by space) AND (current is not space)
        if (!isspace(array[i])) {
            if (i == 0 || isspace(array[i - 1])) {
                array[i] = toupper(array[i]);
            }
            
            // Check if it's the last letter of a word
            // (Either end of string or followed by space)
            if (i == len - 1 || isspace(array[i + 1])) {
                array[i] = toupper(array[i]);
            }
        }
    }
}

int main() {
    char arr1[100] = "hello world example";
    cout << "Before: " << arr1 << endl;
    upperCase(arr1);
    cout << "After: " << arr1 << endl;
    
    char arr2[100] = "a";
    upperCase(arr2);
    cout << "After: " << arr2 << endl; // "A"

    char arr3[100] = "  spaces  ";
    upperCase(arr3);
    cout << "After: '" << arr3 << "'" << endl; // "  Spaces  " -> "  SpaceS  "
    
    return 0;
}
