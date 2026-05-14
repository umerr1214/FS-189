#include <iostream>
#include <cstring>
using namespace std;

int countCharacterOccurrences(const char arr[], char target) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        // Semantic Error: Checking address of target? 
        // Or assigning instead of comparing again? 
        // Or comparing arr (pointer) with target (char)?
        
        // Let's try comparing pointer with integer value of target?
        // if (arr == target) // compile error char* vs char
        
        // Using assignment in condition is classic semantic error
        if (arr[i] = target) { // Assignment: arr[i] becomes target, returns true if target != 0
            count++;
        }
    }
    return count;
}

int main() {
    char arr[] = "abc"; // Must be mutable for assignment to compile (removed const from signature implicitly by implementation, or let's see if compiler allows modifying const char via cast? No.)
    // If signature requires const char[], I can't modify.
    // I need a semantic error that compiles with const char[].
    
    // Comparing addresses?
    // if (&arr[i] == &target) -> always false
    
    // Comparing char with string literal?
    // if (arr[i] == "a") -> compile error
    
    // Using bitwise XOR instead of equality?
    // if (arr[i] ^ target) -> True if they are DIFFERENT. False if EQUAL.
    // Logic reversed semantically.
    
    return 0;
}

// Re-writing with bitwise error
int countCharacterOccurrences_Semantic(const char arr[], char target) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] ^ target) { // Semantic Error: XOR is true when different, false when equal
            count++;
        }
    }
    return count;
}

// But I need to respect the filename 693.cpp
int countCharacterOccurrences(const char arr[], char target) {
     int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] ^ target) { // Semantic Error: XOR logic (counts non-matching chars)
            count++;
        }
    }
    return count;
}
