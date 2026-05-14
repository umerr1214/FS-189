#include <iostream>
#include <cstring>
using namespace std;

int countCharacterOccurrences(const char arr[], char target) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count
} // Syntax Error: Missing semicolon

int main() {
    const char arr[] = "hello world";
    char target = 'l';
    cout << "Occurrences of '" << target << "': " << countCharacterOccurrences(arr, target) << endl;
    return 0;
}
