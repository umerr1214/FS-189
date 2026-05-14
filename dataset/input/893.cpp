#include <iostream>
#include <string>
using namespace std;

int sumOfDigits(int n) {
    // Efficiency/Readability Issue: Converting to string to iterate digits.
    // Allocates memory, parsing overhead. O(log N) space (digits).
    // Arithmetic modulo is O(1) space.
    
    string s = to_string(n);
    int sum = 0;
    for (char c : s) {
        if (isdigit(c)) {
            sum += c - '0';
        }
    }
    return sum;
}

int main() {
    cout << sumOfDigits(12345) << endl;
    return 0;
}
