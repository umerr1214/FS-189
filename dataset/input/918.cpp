#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n < 0) return 0; // Error case
    if (n <= 1) return 1;
    
    // Check for overflow?
    // Max int factorial fits in long long is 20!.
    // If n > 20, it overflows.
    // But typically for basic recursion question, this is acceptable.
    
    return n * factorial(n - 1);
}

int main() {
    cout << "5! = " << factorial(5) << endl; // 120
    cout << "0! = " << factorial(0) << endl; // 1
    cout << "-1! = " << factorial(-1) << endl; // 0
    return 0;
}
