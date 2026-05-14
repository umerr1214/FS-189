#include <iostream>
#include <cstring> // For strcpy and strcat

// Function to concatenate and print C-style strings
void concatenateStrings(char* dest, const char* src1, const char* src2)
{
    strcpy(dest, src1);
    strcat(dest, src2) // Syntax Error: Missing semicolon
    std::cout << "Combined string: " << dest << std::endl;
}

int main() {
    char buffer1[100];
    concatenateStrings(buffer1, "Hello, ", "World!");

    char buffer2[100];
    concatenateStrings(buffer2, "C++ ", "Programming");
    
    return 0;
}