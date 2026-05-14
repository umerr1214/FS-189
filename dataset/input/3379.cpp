#include <iostream> // Required for std::cout and std::endl

int main() {
    // Declare variables
    int intVar = 42;
    float floatVar = 3.14159f;
    char charVar = 'X';

    // Declare and initialize void pointers
    // This approach loses type information and requires explicit casting later,
    // which can be less robust than using type-specific pointers directly.
    void* intPtr = &intVar;
    void* floatPtr = &floatVar;
    void* charPtr = &charVar;

    // Use pointers to print values and memory addresses
    std::cout << "Integer Variable:" << std::endl;
    // Dereferencing void* requires a static_cast back to the original type.
    // If the cast type is wrong, this would lead to undefined behavior.
    std::cout << "  Value: " << *(static_cast<int*>(intPtr)) << std::endl;
    std::cout << "  Address: " << intPtr << std::endl; // std::cout handles void* addresses

    std::cout << "\nFloat Variable:" << std::endl;
    std::cout << "  Value: " << *(static_cast<float*>(floatPtr)) << std::endl;
    std::cout << "  Address: " << floatPtr << std::endl;

    std::cout << "\nChar Variable:" << std::endl;
    // For char, directly printing *(static_cast<char*>(charPtr)) prints the character.
    std::cout << "  Value: " << *(static_cast<char*>(charPtr)) << std::endl;
    std::cout << "  Address: " << charPtr << std::endl; // std::cout handles void* addresses

    return 0;
}