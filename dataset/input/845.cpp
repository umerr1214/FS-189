#include <iostream>
#include <cstring>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const char* str) {
    // Efficiency/Readability: Using std::stack for simple counter problem.
    // O(N) space complexity instead of O(1).
    // Valid for multiple types of braces, but overkill for just '()'.
    
    if (str == nullptr) return false;
    
    stack<char> s;
    string input(str); // Extra allocation
    
    for (char c : input) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty()) return false;
            s.pop();
        }
    }
    
    return s.empty();
}

int main() {
    cout << isBalanced("(())") << endl;
    return 0;
}
