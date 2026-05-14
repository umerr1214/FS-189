#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(int n) {
    // Efficiency/Readability: Converting to string to check palindrome.
    // Allocates memory O(log N) digits.
    // Integer arithmetic O(1) space is preferred for this specific problem (often explicitly asked).
    
    string s = to_string(n);
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}

int main() {
    cout << isPalindrome(121) << endl;
    return 0;
}
