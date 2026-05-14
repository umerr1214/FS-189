#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int binaryToDecimal(const char* binary) {
    int decimal = 0;
    int len = strlen(binary);
    int power = 0;
    
    // Logical Error: Iterating from left to right but increasing power from 0.
    // e.g. "101". '1' at index 0 gets power 0 (value 1). '0' at index 1 gets power 1. '1' at index 2 gets power 2.
    // Result: 1 + 0 + 4 = 5. (Wait, 101 is 5).
    // Let's trace carefully: 
    // i=0 ('1'). decimal += 2^0 = 1. power=1.
    // i=1 ('0'). power=2.
    // i=2 ('1'). decimal += 2^2 = 4. power=3.
    // Result 5. 
    // Wait, "101" binary is 5. But "10" binary is 2.
    // Logic: i=0 ('1'). dec += 1. power=1. i=1 ('0'). power=2.
    // Result 1. "10" is 2.
    // So this logic reverses the string effectively.
    // "110" -> '1' (2^0) + '1' (2^1) + '0' = 3. Should be 6.
    
    for (int i = 0; i < len; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

int main() {
    const char* bin = "110";
    // Expected: 6
    // Actual: 3 (because '1' at start gets 2^0, '1' at mid gets 2^1)
    cout << "Binary " << bin << " is " << binaryToDecimal(bin) << " in decimal." << endl;
    return 0;
}
