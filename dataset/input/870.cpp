#include <iostream>
#include <cstring>
using namespace std;

int binaryToDecimal(const char* binary) {
    if (binary == nullptr) return 0; // Or -1
    
    int decimal = 0;
    for (int i = 0; binary[i] != '\0'; i++) {
        // Validate input
        if (binary[i] != '0' && binary[i] != '1') {
            return -1; // Error code for invalid format
        }
        
        // Horner's method / Shift
        decimal = (decimal << 1) + (binary[i] - '0');
    }
    return decimal;
}

int main() {
    cout << "1011 -> " << binaryToDecimal("1011") << endl; // 11
    cout << "110 -> " << binaryToDecimal("110") << endl; // 6
    cout << "222 -> " << binaryToDecimal("222") << endl; // -1
    cout << "NULL -> " << binaryToDecimal(NULL) << endl; // 0
    return 0;
}
