#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum
} // Syntax Error: Missing semicolon

int main() {
    int n = 12345;
    cout << "Sum of digits of " << n << " is " << sumOfDigits(n) << endl;
    return 0;
}
