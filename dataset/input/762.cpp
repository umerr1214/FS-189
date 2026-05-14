#include <iostream>
#include <cstring>
using namespace std;

void encrypt(char arr[]) {
    if (arr == nullptr) return;
    
    // Note: We use unsigned char cast to ensure consistent wrapping behavior
    // though for simple char += int it relies on default char signedness.
    // Standard char overflow is implementation defined if signed, but usually wraps.
    
    for (int i = 0; arr[i] != '\0'; i++) {
        arr[i] = (char)(arr[i] + i);
    }
}

void decrypt(char arr[]) {
    if (arr == nullptr) return;
    
    for (int i = 0; arr[i] != '\0'; i++) {
        arr[i] = (char)(arr[i] - i);
    }
}

int main() {
    char arr[100] = "Hello World";
    cout << "Original: " << arr << endl;
    
    encrypt(arr);
    cout << "Encrypted: " << arr << endl;
    
    decrypt(arr);
    cout << "Decrypted: " << arr << endl;
    
    // Test with NULL
    encrypt(NULL);
    decrypt(NULL);
    
    return 0;
}
