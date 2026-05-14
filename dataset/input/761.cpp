#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void encrypt(char arr[]) {
    // Efficiency Issue: Using recursion for simple iteration O(N) stack space.
    
    static int i = 0; // Using static for recursion index (bad practice for reentrancy)
    if (arr[i] == '\0') {
        i = 0; // Reset for next call? Hacky.
        return;
    }
    
    arr[i] += i;
    i++;
    encrypt(arr); // Recursive call
    // Note: 'i' will be reset only at the end, but since 'i' is static, it messes up if we call encrypt again?
    // Wait, recursion keeps calling encrypt.
    // 'i' increments.
    // When base case reached, i=0.
    // This actually works ONCE.
    // But recursion depth O(N) might overflow stack for long strings.
}

void decrypt(char arr[]) {
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        arr[i] -= i;
    }
}

int main() {
    char arr[100] = "Hello";
    encrypt(arr);
    cout << "Encrypted: " << arr << endl;
    decrypt(arr);
    cout << "Decrypted: " << arr << endl;
    return 0;
}
