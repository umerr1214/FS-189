#include <iostream>
#include <cstring>
using namespace std;

bool isBalanced(const char* str) {
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
    return balance == 0
} // Syntax Error: Missing semicolon

int main() {
    const char* str1 = "(())";
    const char* str2 = "(()))";
    
    if (isBalanced(str1)) cout << str1 << " is balanced" << endl;
    else cout << str1 << " is not balanced" << endl;
    
    if (isBalanced(str2)) cout << str2 << " is balanced" << endl;
    else cout << str2 << " is not balanced" << endl;
    
    return 0;
}
