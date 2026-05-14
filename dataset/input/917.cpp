#include <iostream>
#include <vector>
using namespace std;

long long factorial(int n) {
    // Efficiency Issue: Recursion is fine O(N).
    // But what if we do something silly like creating a vector of size N every step?
    
    if (n <= 1) return 1;
    
    vector<int> dummy(n); // Allocating memory O(N) every step
    // Total space O(N^2)
    
    return n * factorial(n - 1);
}

int main() {
    cout << factorial(5) << endl;
    return 0;
}
