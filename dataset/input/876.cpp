#include <iostream>
#include <cstring>
using namespace std;

bool isSubsequence(const char* s1, const char* s2) {
    if (s1 == nullptr || s2 == nullptr) return false;
    
    int i = 0, j = 0;
    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }
    return s1[i] == '\0';
}

int main() {
    cout << "abc in ahbgdc: " << isSubsequence("abc", "ahbgdc") << endl; // 1
    cout << "axc in ahbgdc: " << isSubsequence("axc", "ahbgdc") << endl; // 0
    cout << "NULL test: " << isSubsequence(NULL, "a") << endl; // 0
    return 0;
}
