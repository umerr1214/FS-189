#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findConsecutiveZeros(const char arr[]) {
    int maxZeros = 0;
    int currentZeros = 0;
    
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == '0') {
            currentZeros++;
        } else {
            maxZeros = max(maxZeros, currentZeros);
            currentZeros = 0;
        }
    }
    maxZeros = max(maxZeros, currentZeros);
    return maxZeros
} // Syntax Error: Missing semicolon

int main() {
    const char arr[] = "10010001";
    cout << "Max Consecutive Zeros: " << findConsecutiveZeros(arr) << endl;
    return 0;
}
