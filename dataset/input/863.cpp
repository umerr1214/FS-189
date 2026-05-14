#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
    // Efficiency/Readability:
    // Using simple subtraction based Euclidean algorithm?
    // It's O(max(a,b)) in worst case (e.g. gcd(1000, 1)). Modulo is O(log(min(a,b))).
    // Subtraction is inefficient for large difference.
    
    a = abs(a);
    b = abs(b);
    
    if (a == 0) return b;
    if (b == 0) return a;
    
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main() {
    // 100000000, 1 -> 100 million subtractions!
    cout << gcd(48, 18) << endl;
    return 0;
}
