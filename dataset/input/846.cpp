#include <iostream>
#include <cstring>
using namespace std;

bool isBalanced(const char* str) {
    if (str == nullptr) return true; // Empty/Null usually considered balanced or false depending on spec. 
    // Usually empty string is balanced. NULL is debatable, let's say true (empty) or false (invalid).
    // Let's return true (treat as empty) for robustness, or false. 
    // Standard validation often returns false for NULL.
    // But empty string is definitely true.
    if (str == nullptr) return false; // Let's say invalid input is false
    
    int balance = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            balance++;
        } else if (str[i] == ')') {
            balance--;
        }
        
        if (balance < 0) {
            return false;
        }
    }
    
    return balance == 0;
}

int main() {
    cout << isBalanced("(())") << endl; // 1
    cout << isBalanced("(()") << endl;  // 0
    cout << isBalanced(")(()") << endl; // 0
    cout << isBalanced(NULL) << endl;   // 0
    return 0;
}
