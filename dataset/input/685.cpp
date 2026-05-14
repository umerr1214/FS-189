#include <iostream>
#include <cstring>
using namespace std;

void replaceSubstring(char arr[], const char target[], const char replacement[]) {
    int targetLen = strlen(target);
    int repLen = strlen(replacement);
    int arrLen = strlen(arr);
    
    char buffer[1000];
    buffer[0] = '\0';
    
    int i = 0;
    while (i < arrLen) {
        if (strstr(&arr[i], target) == &arr[i]) {
            strcat(buffer, replacement);
            i += targetLen;
        } else {
            int len = strlen(buffer);
            buffer[len] = arr[i];
            buffer[len + 1] = '\0';
            i++;
        }
    }
    strcpy(arr, buffer)
} // Syntax Error: Missing semicolon

int main() {
    char arr[100] = "hello world, hello universe";
    replaceSubstring(arr, "hello", "hi");
    cout << "Result: " << arr << endl;
    return 0;
}
