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
        
        // Convert count to string
        char countStr[10];
        sprintf(countStr, "%d", count);
        for (int j = 0; countStr[j] != '\0'; j++) {
            output[k++] = countStr[j];
        }
    }
    output[k] = '\0'
} // Syntax Error: Missing semicolon

int main() {
    const char* str = "AAABBBCCCDDE";
    char encoded[100];
    runLengthEncode(str, encoded);
    cout << "Encoded: " << encoded << endl;
    return 0;
}
