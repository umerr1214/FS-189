#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void runLengthEncode(const char* input, char* output) {
    int len = strlen(input);
    int k = 0;
    
    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        output[k++] = input[i];
        
        // Semantic Error: Assigning integer `count` directly to char `output[k]`?
        // output[k++] = count; 
        // If count is 3, it stores ASCII 3 (ETX), not character '3'.
        // This is a semantic misuse of types.
        // It technically compiles but produces non-printable string.
        
        output[k++] = count; // Semantic Error: Stores int value as char, not ASCII digit
    }
    output[k] = '\0';
}

int main() {
    const char* str = "AAABBB";
    // Expected: "A3B3"
    // Actual: "A\x03B\x03"
    char encoded[100];
    runLengthEncode(str, encoded);
    cout << "Encoded: " << encoded << endl; // Prints A(heart)B(heart) on some terminals
    return 0;
}
