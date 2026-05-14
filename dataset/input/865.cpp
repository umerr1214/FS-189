#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int binaryToDecimal(const char* binary) {
    int decimal = 0;
    int len = strlen(binary);
    int power = 0;
    
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal
} // Syntax Error: Missing semicolon

int main() {
    const char* bin = "1011";
    cout << "Binary " << bin << " is " << binaryToDecimal(bin) << " in decimal." << endl;
    return 0;
}
