#include <iostream>
#include <cstring>
using namespace std;

bool isBalanced(const char* str) {
    int balance = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        // Semantic Error: Using assignment in condition?
        // if (str[i] = '(') -> sets char to '(', returns true.
        // balance always increments.
        
        // Let's use assignment.
        if (str[i] = '(') { 
             balance++;
        } else if (str[i] == ')') {
             balance--;
        }
    }
    return balance == 0;
}

int main() {
    char str[] = ")))"; // Mutable for assignment
    // Loop sets every char to '('.
    // balance becomes 3. Returns false (unbalanced).
    // Wait, if input is "))", it becomes "(((". Balance 3. Returns false.
    // Logic seems correct (unbalanced), but for WRONG REASON.
    // Let's use input "(((".
    // It stays "(((". Balance 3. Returns false.
    
    // Let's find a case where it returns True incorrectly.
    // It always increments balance. balance > 0 always.
    // It never returns true unless string is empty.
    
    // Let's try a different semantic error.
    // Using bitwise XOR?
    // if (str[i] ^ '(') -> True if different. False if equal.
    
    return 0;
}

// Re-write with bitwise error
bool isBalanced_Semantic(const char* str) {
    int balance = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] ^ '(') { // True if NOT '('
            // If it's ')', it enters here.
            balance++; 
        } else {
            // If it IS '(', it goes to else? No, `else if` logic needs check.
            
            // Let's simplify logic for error.
            if (str[i] ^ '(') balance++;
            else balance--;
        }
        if (balance < 0) return false;
    }
    return balance == 0;
}
// This logic: if ')' -> balance++. if '(' -> balance--.
// So "))" -> balance 2. False.
// "((" -> balance -2. False (early exit).
// "()" -> '(' -> -1 (exit).
// ")(" -> ')' -> 1. '(' -> 0. True!
// So ")(" is valid? Yes.
