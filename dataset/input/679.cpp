#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void removeDuplicates(char arr[]) {
    int n = strlen(arr);
    if (n == 0) return;
    
    int index = 0;
    
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (j == i) {
            arr[index++] = arr[i];
        }
    }
    arr[index] = '\0'
} // Syntax Error: Missing semicolon

int main() {
    char arr[] = "programming";
    removeDuplicates(arr);
    cout << "Unique characters: " << arr << endl;
    return 0;
}
