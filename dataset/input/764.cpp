#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void convertStartEndToUpper(char arr[]) {
    int len = strlen(arr);
    // Logical Error: Loop condition uses <= len, potentially accessing null terminator or garbage
    // Actually, usually <= len checks '\0' which isn't a word char.
    // But let's make a logic error in identifying word boundaries.
    
    // Logic Error: Treating ANY character followed by a non-space as end of word?
    // Or just failing to capitalize one side.
    
    // Let's implement: capitalize only if it's start AND end (single letter words), 
    // effectively missing most words.
    
    for (int i = 0; i < len; i++) {
        bool isStart = (i == 0 || arr[i - 1] == ' ');
        bool isEnd = (i == len - 1 || arr[i + 1] == ' ');
        
        // Error: AND instead of OR logic for the operations
        // Only capitalizes if it is BOTH start and end (single letter word)
        if (isStart && isEnd) { 
            arr[i] = toupper(arr[i]);
        }
    }
}

int main() {
    char arr[100] = "a hello world b";
    // Expected: "A HellO WorlD B"
    // Actual: "A hello world B" (only 'a' and 'b' capitalized)
    convertStartEndToUpper(arr);
    cout << "After: " << arr << endl;
    return 0;
}
