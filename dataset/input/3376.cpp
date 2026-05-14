#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    int myInt = 10;
    float myFloat = 20.5f;
    char myChar = 'A';

    int* pInt = &myInt;
    float* pFloat = &myFloat;
    char* pChar = &myChar;

    std::cout << "Integer Variable:" << std::endl;
    std::cout << "Value: " << *pInt << std::endl;
    std::cout << "Address: " << pInt std::endl; // Syntax Error: Missing semicolon here

    std::cout << "\nFloat Variable:" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Value: " << *pFloat << std::endl;
    std::cout << "Address: " << pFloat << std::endl;

    std::cout << "\nChar Variable:" << std::endl;
    std::cout << "Value: " << *pChar << std::endl;
    std::cout << "Address: " << static_cast<void*>(pChar) << std::endl;

    return 0;
}