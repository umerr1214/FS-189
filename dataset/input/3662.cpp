#include <iostream> // Included for potential future use or if user changes to cout
#include <cstdio>   // For printf
#include <iomanip>  // For std::hex, std::showbase if we were to use cout (not used here)

int main() {
    int x = 42; // Variable name 'x' is not very descriptive, impacting readability.
    int *p;     // Pointer declaration style (space before 'p') and name 'p' are less readable/standard.
    p = &x;     // Assignment on a separate line from declaration, slightly less concise.

    // Using printf for output, which is C-style I/O and generally less idiomatic C++ than iostream.
    // Also, the output messages are somewhat terse.
    printf("Value of variable: %d\n", x);
    printf("Value through pointer: %d\n", *p);
    // %p prints the address. On many systems, it prefixes with 0x, but this isn't strictly guaranteed by standard.
    printf("Address of var: %p\n", (void*)&x);
    printf("Address in ptr: %p\n", (void*)p);

    // This print statement is somewhat redundant and doesn't add much value, slightly affecting efficiency and readability.
    printf("--- Confirmed values ---\n");
    printf("Original var: %d\n", x);

    return 0;
}