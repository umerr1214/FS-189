#include <iostream>
#include <cstring>
using namespace std;

void encrypt(char arr[]) {
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        // Semantic Error: Assigning integer `i` to the character? 
        // arr[i] = i; // This replaces the char with the index (non-printable usually).
        // That's a valid logical operation but semantically deletes data.
        
        // Let's use assignment in expression.
        // arr[i] += (i = 5); // Modifies i inside loop? Dangerous.
        
        // Let's try: arr[i] = arr[i] + " "; // Adding string literal to char? Compile error.
        
        // Let's confuse index with value in a semantic way.
        // arr[arr[i]] = ...
        
        // Or using `sizeof` on array parameter again?
        
        // Let's use assignment in `if` (even though no `if` is needed, let's add one).
        // if (arr[i] = '\0') break; // Terminates string early.
        
        // Let's try:
        // arr[i] += &i; // Adding address of i? Compile error.
        
        // How about using bitwise shift?
        arr[i] <<= i; // Shifting char bits by index. For i >= 8, this zeroes it out or is UB.
        // This is semantically "encrypting" but destructively.
    }
}

void decrypt(char arr[]) {
    // Cannot decrypt shift easily
}

int main() {
    char arr[100] = "Hello";
    encrypt(arr);
    return 0;
}
