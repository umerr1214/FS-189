#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int countCharacterOccurrences(const char arr[], char target) {
    // Efficiency Issue: Calling strlen in the loop condition
    // For some compilers/settings, this makes it O(N^2) because strlen is O(N).
    // Better: int len = strlen(arr); for (int i=0; i<len; ++i) OR for (int i=0; arr[i]!='\0'; ++i)
    
    int count = 0;
    for (int i = 0; i < strlen(arr); i++) { // Re-evaluates strlen every iteration
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    const char arr[] = "hello world";
    cout << countCharacterOccurrences(arr, 'l') << endl;
    return 0;
}
