#include <iostream>
#include <cmath>
using namespace std;

int sumOfDigits(int n) {
    n = abs(n); // Handle negative numbers
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    cout << "12345 -> " << sumOfDigits(12345) << endl; // 15
    cout << "0 -> " << sumOfDigits(0) << endl; // 0
    cout << "-123 -> " << sumOfDigits(-123) << endl; // 6
    return 0;
}
