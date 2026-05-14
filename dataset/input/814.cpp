#include <iostream>
#include <cstring>
using namespace std;

bool areAnagrams(const char* str1, const char* str2) {
    // Robustness Issue: No NULL check.
    
    // Crash if str1 or str2 is NULL
    if (strlen(str1) != strlen(str2)) return false;
    
    int count[256] = {0};
    // ...
    return true;
}

int main() {
    // Crash
    // areAnagrams(NULL, "a");
    return 0;
}
