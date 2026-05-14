#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findConsecutiveZeros(const char arr[]) {
    if (arr == nullptr) {
        return 0;
    }

    int maxZeros = 0;
    int currentZeros = 0;
    
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == '0') {
            currentZeros++;
        } else {
            if (currentZeros > maxZeros) {
                maxZeros = currentZeros;
            }
            currentZeros = 0;
        }
    }
    // Check after loop finishes in case array ends with zeros
    if (currentZeros > maxZeros) {
        maxZeros = currentZeros;
    }
    
    return maxZeros;
}

int main() {
    const char arr1[] = "10010001";
    cout << "Max Consecutive Zeros: " << findConsecutiveZeros(arr1) << endl;
    
    const char arr2[] = "0000";
    cout << "Max Consecutive Zeros: " << findConsecutiveZeros(arr2) << endl;

    const char* arr3 = NULL;
    cout << "Max Consecutive Zeros: " << findConsecutiveZeros(arr3) << endl;

    return 0;
}
