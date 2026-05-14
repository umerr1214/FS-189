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
    for (int i = 0; i < len; i++) {
        arr[i] -= i;
    }
}

int main() {
    char arr[100] = "Hello World";
    cout << "Original: " << arr << endl;
    
    encrypt(arr);
    cout << "Encrypted: " << arr << endl;
    
    decrypt(arr) // Syntax Error: Missing semicolon
    cout << "Decrypted: " << arr << endl;
    
    return 0;
}
