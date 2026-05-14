#include <iostream>
#include <cmath> // for abs
using namespace std;

int gcd(int a, int b) {
    // Use absolute values to handle negatives
    a = abs(a);
    b = abs(b);
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    cout << "GCD(48, 18) = " << gcd(48, 18) << endl;
    cout << "GCD(-48, 18) = " << gcd(-48, 18) << endl;
    cout << "GCD(48, -18) = " << gcd(48, -18) << endl;
    cout << "GCD(0, 5) = " << gcd(0, 5) << endl;
    
    return 0;
}
