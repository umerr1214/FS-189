#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    int myInt = 10;
    float myFloat = 20.5f;
    char myChar = 'A';

    // Correct pointer for myInt
    int* pInt = &myInt;

    // Semantic Error: Initialize an int* with the address of a float using reinterpret_cast.
    // This allows compilation but leads to incorrect interpretation of data when dereferenced.
    int* pFloat_sem = reinterpret_cast<int*>(&myFloat);

    // Correct pointer for myChar
    char* pChar = &myChar;

    std::cout << "Integer Variable:" << std::endl;
    std::cout << "Value: " << *pInt << std::endl;
    std::cout << "Address: " << pInt << std::endl;

    std::cout << "\nFloat Variable (Semantic Error - interpreted as int):" << std::endl;
    // Dereferencing pFloat_sem will read 4 bytes from myFloat's location and interpret them as an integer.
    // This value will not be 20.5 or any meaningful integer representation of 20.5.
    std::cout << "Value: " << *pFloat_sem << std::endl; // Semantic error here: misinterpreting float bits as int
    std::cout << "Address: " << pFloat_sem << std::endl; // Address itself is correct (of myFloat)

    std::cout << "\nChar Variable:" << std::endl;
    std::cout << "Value: " << *pChar << std::endl;
    std::cout << "Address: " << static_cast<void*>(pChar) << std::endl;

    return 0;
}