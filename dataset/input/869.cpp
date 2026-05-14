#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int binaryToDecimal(const char* binary) {
    // Efficiency/Readability: Using `pow` function in loop.
    // `pow` is floating point and expensive.
    // Can be done with bitwise shift or simple multiplication accumulators.
    
    int decimal = 0;
    int len = strlen(binary);
    
    for (int i = 0; i < len; i++) {
        if (binary[i] == '1') {
            // Calculating 2^(len-1-i) repeatedly
            decimal += pow(2, len - 1 - i);
        }
    }
    return decimal;
}

int main() {
    cout << binaryToDecimal("1011") << endl;
    return 0;
}
