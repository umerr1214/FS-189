#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        // Semantic Error: Confusion between bitwise operators and arithmetic?
        // Or using assignment.
        
        // Let's use `n & 10`. 
        // `n % 10` gives last digit.
        // `n & 10` checks if bit 8 and bit 2 are set in specific pattern? No.
        // 10 is 1010 binary.
        // This is semantic error (using wrong operator for intended math).
        
        sum += n & 10; // Logic for "last digit" is %, & is bitwise AND
        n /= 10;
    }
    return sum;
}

int main() {
    int n = 123;
    // 123 (1111011) & 1010 = 1010 (10). Sum += 10. n=12.
    // 12 (1100) & 1010 = 1000 (8). Sum += 8. n=1.
    // 1 (0001) & 1010 = 0. Sum += 0. n=0.
    // Result 18. Expected 6.
    
    cout << "Sum of digits of " << n << " is " << sumOfDigits(n) << endl;
    return 0;
}
