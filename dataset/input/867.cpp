#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int binaryToDecimal(const char* binary) {
    int decimal = 0;
    int len = strlen(binary);
    int power = 0;
    
    for (int i = len - 1; i >= 0; i--) {
        // Semantic Error: Checking pointer address logic?
        // Or using '1' as int 1?
        
        // Let's use:
        // if (binary[i] & 1) // Checks if ASCII value is odd. '1' (49) is odd. '0' (48) is even.
        // This actually works correctly for '0' and '1'.
        // We need something that breaks semantically.
        
        // Let's use string literal comparison again?
        // if (binary[i] == "1") // Compile error
        
        // Let's use assignment in condition.
        // if (binary[i] = '1')
        // But binary is const char*. So assignment fails.
        
        // Let's use subtraction of unrelated pointers?
        
        // Let's use:
        // decimal += (binary[i]) * pow(2, power); 
        // This adds the ASCII value ('0' or '1') times power.
        // '0' is 48, '1' is 49.
        // Result is huge.
        // This is a semantic error (using char value directly as numeric digit).
        
        decimal += binary[i] * pow(2, power); // Adds ASCII value directly
        power++;
    }
    return decimal;
}

int main() {
    const char* bin = "10";
    // i=1 ('0'=48). dec += 48 * 1 = 48.
    // i=0 ('1'=49). dec += 49 * 2 = 98.
    // Total 146. Expected 2.
    cout << "Binary " << bin << " is " << binaryToDecimal(bin) << " in decimal." << endl;
    return 0;
}
