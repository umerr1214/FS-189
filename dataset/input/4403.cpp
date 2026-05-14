#include <iostream>
#include <cstring> // For strcpy

// Function to concatenate and print C-style strings
// Logical Error: The function uses strcpy twice, effectively only copying src2 to dest,
// instead of concatenating src1 and src2.
void concatenateStrings(char* dest, const char* src1, const char* src2)
{
    strcpy(dest, src1); // Copies src1 to dest
    strcpy(dest, src2); // Overwrites dest with src2 - this is the logical error
    std::cout << "Combined string: " << dest << std::endl;
}

int main() {
    char buffer1[100];
    concatenateStrings(buffer1, "Hello, ", "World!"); // Expected: "Hello, World!" | Actual: "World!"

    char buffer2[100];
    concatenateStrings(buffer2, "C++ ", "Programming"); // Expected: "C++ Programming" | Actual: "Programming"
    
    return 0;
}