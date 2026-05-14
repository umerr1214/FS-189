#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void runLengthEncode(const char* input, char* output) {
    int len = strlen(input);
    int k = 0;
    
    for (int i = 0; i < len; i++) {
        int count = 1;
        // Logical Error: Incrementing 'i' inside the inner loop correctly, 
        // BUT the outer loop ALSO increments 'i' because of `for (int i...; i++)`.
        // This causes the character immediately following a run to be skipped.
        // e.g., "AAAB" -> i=0. inner loop i->2. Outer loop i->3. "B" is processed.
        // Wait, if i=2 at end of inner loop, outer loop i++ makes it 3. input[3] is 'B'.
        // So "AAAB" works.
        // What about "AAB"?
        // i=0. Inner loop i->1. Outer loop i->2. input[2] is 'B'. Correct.
        
        // Let's break the logic differently.
        // Forgetting to reset count? No, defined inside.
        // Using `if` instead of `while` for counting?
        
        if (i < len - 1 && input[i] == input[i + 1]) { // Using IF instead of WHILE
            count++;
            i++;
        }
        
        output[k++] = input[i];
        
        // Appending count
        char countStr[10];
        sprintf(countStr, "%d", count);
        for (int j = 0; countStr[j] != '\0'; j++) {
            output[k++] = countStr[j];
        }
    }
    output[k] = '\0';
}

int main() {
    const char* str = "AAAB";
    // Expected: "A3B1"
    // Actual with IF: 
    // i=0. input[0]==input[1] ('A'=='A'). count=2. i=1.
    // Output "A2".
    // Outer loop i becomes 2. input[2] is 'A'.
    // i=2. input[2]!=input[3] ('A'!='B'). count=1.
    // Output "A2A1".
    // Outer loop i becomes 3. input[3] is 'B'.
    // Output "A2A1B1".
    // Correct string "AAAB" -> "A3B1". Result "A2A1B1".
    
    char encoded[100];
    runLengthEncode(str, encoded);
    cout << "Encoded: " << encoded << endl;
    return 0;
}
