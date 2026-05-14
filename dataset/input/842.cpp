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
        
        // Logical Error: Missing check for negative balance during iteration.
        // E.g., ")(()" -> balance goes -1, then 0. 
        // Returns true at the end because final balance is 0.
        // But it's invalid.
    }
    return balance == 0;
}

int main() {
    const char* str = ")(()"; 
    // Expected: False
    // Actual: True
    if (isBalanced(str)) cout << str << " is balanced" << endl;
    else cout << str << " is not balanced" << endl;
    return 0;
}
