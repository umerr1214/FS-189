#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void removeDuplicates(char arr[]) {
    // Robustness Issue: No NULL check.
    // strlen(NULL) crashes.
    
    int n = strlen(arr);
    
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
    arr[index] = '\0';
}

int main() {
    char* arr = NULL;
    // Crash
    // removeDuplicates(arr);
    return 0;
}
