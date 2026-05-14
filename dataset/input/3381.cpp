#include <iostream> // Required for std::cout and std::endl
#include <iomanip>  // For std::fixed and std::setprecision for consistent float output

int main() {
    // Declare variables with descriptive names
    int integerVariable = 100;
    float floatVariable = 123.456f;
    char charVariable = 'A';

    // Declare and initialize pointers for each variable directly
    int* ptrToInt = &integerVariable;
    float* ptrToFloat = &floatVariable;
    char* ptrToChar = &charVariable;

    // Use pointers to print the values and memory addresses of the original variables
    std::cout << "Integer Variable:" << std::endl;
    std::cout << "  Value: " << *ptrToInt << std::endl;
    std::cout << "  Address: " << ptrToInt << std::endl;

    std::cout << "\nFloat Variable:" << std::endl;
    // Using std::fixed and std::setprecision for consistent float output format
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "  Value: " << *ptrToFloat << std::endl;
    std::cout << "  Address: " << ptrToFloat << std::endl;

    std::cout << "\nChar Variable:" << std::endl;
    std::cout << "  Value: " << *ptrToChar << std::endl;
    // Cast char* to void* when printing its address to prevent std::cout from
    // interpreting it as a C-style string, which is standard practice.
    std::cout << "  Address: " << static_cast<void*>(ptrToChar) << std::endl;

    return 0;
}