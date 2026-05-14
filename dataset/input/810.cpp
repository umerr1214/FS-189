#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void runLengthEncode(const char* input, char* output) {
    if (input == nullptr || output == nullptr) return;
    
    int len = strlen(input);
    int k = 0;
    
    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        
        output[k++] = input[i];
        
        // Convert count to string manually or via sprintf
        // sprintf is safe enough if buffer is large enough for int
        char countStr[12];
        sprintf(countStr, "%d", count);
        for (int j = 0; countStr[j] != '\0'; j++) {
            output[k++] = countStr[j];
        }
    }
    output[k] = '\0';
}

int main() {
    const char* str1 = "AAABBBCCCDDE";
    char res1[100];
    runLengthEncode(str1, res1);
    cout << "Original: " << str1 << " Encoded: " << res1 << endl;
    
    const char* str2 = "ABCD";
    char res2[100];
    runLengthEncode(str2, res2);
    cout << "Original: " << str2 << " Encoded: " << res2 << endl;
    
    runLengthEncode(NULL, res2); // Safe
    
    return 0;
}
