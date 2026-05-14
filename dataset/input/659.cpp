#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int findConsecutiveZeros(const char arr[]) {
    // Efficiency/Readability Issue: Creating a string copy or vector just to iterate
    // O(N) space and extra allocation/copy time.
    // Iterating the C-string directly is O(1) space.
    
    if (arr == nullptr) return 0;

    string s(arr); // Allocation and copy
    int maxZeros = 0;
    int currentZeros = 0;
    
    for (char c : s) {
        if (c == '0') {
            currentZeros++;
        } else {
            maxZeros = max(maxZeros, currentZeros);
            currentZeros = 0;
        }
    }
    maxZeros = max(maxZeros, currentZeros);
    return maxZeros;
}

int main() {
    const char arr[] = "10010001";
    cout << "Max Consecutive Zeros: " << findConsecutiveZeros(arr) << endl;
    return 0;
}
