#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void replaceSubstring(char arr[], const char target[], const char replacement[]) {
    if (arr == nullptr || target == nullptr || replacement == nullptr) return;
    
    int targetLen = strlen(target);
    int repLen = strlen(replacement);
    
    if (targetLen == 0) return; // Prevent infinite loop if target is empty
    
    // Calculate new length to ensure buffer size
    int count = 0;
    char *p = arr;
    while ((p = strstr(p, target)) != nullptr) {
        count++;
        p += targetLen;
    }
    
    int newLen = strlen(arr) + count * (repLen - targetLen);
    
    // We assume 'arr' is large enough to hold the result as per standard C-style interface contract
    // (or we would need a max size param). For safety in this specific task logic, we use a temp buffer.
    
    char* buffer = (char*)malloc(newLen + 1);
    if (buffer == nullptr) return;
    
    char* src = arr;
    char* dst = buffer;
    
    while (*src) {
        if (strncmp(src, target, targetLen) == 0) {
            strcpy(dst, replacement);
            dst += repLen;
            src += targetLen;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';
    
    strcpy(arr, buffer);
    free(buffer);
}

int main() {
    char arr[100] = "hello world, hello universe";
    replaceSubstring(arr, "hello", "hi");
    cout << "Result: " << arr << endl;
    
    char arr2[100] = "aaaa";
    replaceSubstring(arr2, "aa", "b");
    cout << "Result: " << arr2 << endl; // "bb"
    
    return 0;
}
