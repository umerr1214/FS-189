#include <iostream>
#include <cstring>
using namespace std;

bool isBalanced(const char* str) {
    // Robustness Issue: No NULL check.
    
    int balance = 0;
    // Crash if str is NULL
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            balance++;
        } else if (str[i] == ')') {
            balance--;
        }
        if (balance < 0) return false;
    }
    return balance == 0;
}

int main() {
    // Crash
    // isBalanced(NULL);
    return 0;
}
