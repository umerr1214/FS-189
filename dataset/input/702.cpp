#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void capitalizeWords(char arr[]) {
    if (arr == nullptr) return;

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
}

int main() {
    char arr1[] = "hello world";
    capitalizeWords(arr1);
    cout << "Result: " << arr1 << endl;
    
    char arr2[] = "  multiple   SPACES  ";
    capitalizeWords(arr2);
    cout << "Result: '" << arr2 << "'" << endl;
    
    char arr3[] = "ONE";
    capitalizeWords(arr3);
    cout << "Result: " << arr3 << endl;

    capitalizeWords(NULL);
    
    return 0;
}
