#include <iostream>
#include <cstring> // Included but not used for its primary string manipulation functions

// Function to concatenate and print C-style strings
// Semantic Error: The function ignores the 'dest' buffer for storing the concatenated string.
// Instead, it directly prints the two input strings, bypassing the intended use of 'dest'.
void concatenateStrings(char* dest, const char* src1, const char* src2)
{
    // The 'dest' parameter is provided, implying it should be used to store the combined string.
    // However, this implementation prints 'src1' and 'src2' directly, effectively ignoring 'dest'
    // for its primary purpose of holding the concatenated result.
    // While the output is correct, the function's contract regarding 'dest' is violated.
    std::cout << "Combined string: " << src1 << src2 << std::endl;
}

int main() {
    char buffer1[100]; // This buffer is allocated but not utilized by the function for concatenation.
    concatenateStrings(buffer1, "Hello, ", "World!");

    char buffer2[100];
    concatenateStrings(buffer2, "C++ ", "Programming");
    
    return 0;
}