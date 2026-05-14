#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int binaryToDecimal(const char* binary) {
    // Robustness Issue: No NULL check.
    // No validation that chars are '0' or '1'.
    
    int len = strlen(binary); // Crash if NULL
    int decimal = 0;
    int power = 0;
    
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        } else if (binary[i] != '0') {
            // Should error here, but ignores it (robustness issue, accepts garbage as 0)
        }
        power++;
    }
    return decimal;
}

int main() {
    // Crash
    // binaryToDecimal(NULL);
    return 0;
}
