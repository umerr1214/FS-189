#include <iostream>
#include <cstring>
using namespace std;

int countCharacterOccurrences(const char arr[], char target) {
    if (arr == nullptr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    const char arr[] = "hello world";
    cout << "Occurrences of 'l': " << countCharacterOccurrences(arr, 'l') << endl;
    
    cout << "Occurrences of 'z': " << countCharacterOccurrences(arr, 'z') << endl;
    
    cout << "Occurrences in NULL: " << countCharacterOccurrences(NULL, 'a') << endl;
    
    return 0;
}
