#include <iostream>
#include <cstring>
using namespace std;

int countCharacterOccurrences(const char arr[], char target) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == target) {
            // Logical Error: Failing to increment count, or incrementing wrong variable, or loop logic wrong.
            // Let's increment loop index 'i' instead of count
            i++; 
        }
    }
    return count;
}

int main() {
    const char arr[] = "hello world";
    char target = 'l';
    // Expected: 3
    // Actual: 0 (and skips characters in loop)
    cout << "Occurrences of '" << target << "': " << countCharacterOccurrences(arr, target) << endl;
    return 0;
}
