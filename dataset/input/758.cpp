#include <iostream>
#include <cstring>
using namespace std;

void encrypt(char arr[]) {
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        arr[i] += i;
    }
}

void decrypt(char arr[]) {
    int len = strlen(arr);
    // Logical Error: Using '+=' instead of '-=' in decrypt, effectively double encrypting
    for (int i = 0; i < len; i++) {
        arr[i] += i; 
    }
}

int main() {
    char arr[100] = "Hello";
    // Encrypt: H(0) e(1) l(2) l(3) o(4) -> H f n o s
    // Decrypt should subtract. 
    // Error Decrypt: H(0) f(1) n(2) o(3) s(4) -> H g p r w
    
    encrypt(arr);
    cout << "Encrypted: " << arr << endl;
    
    decrypt(arr);
    cout << "Decrypted: " << arr << endl;
    return 0;
}
