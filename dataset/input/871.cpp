#include <iostream>
#include <cstring>
using namespace std;

bool isSubsequence(const char* s1, const char* s2) {
    int i = 0, j = 0;
    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }
    return s1[i] == '\0'
} // Syntax Error: Missing semicolon

int main() {
    cout << "Is 'abc' subseq of 'ahbgdc'? " << isSubsequence("abc", "ahbgdc") << endl;
    return 0;
}
