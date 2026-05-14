#include <iostream>

int main() {
    double myValue = 123.45;
    // Semantic Error: Declaring an int pointer and reinterpreting the address of a double.
    // This is semantically incorrect because dereferencing an int* on a double's memory location
    // will misinterpret the stored data, even though the address itself is valid.
    int* ptrToValue = reinterpret_cast<int*>(&myValue);

    // This will print an incorrect value because the memory for a double is read as an int.
    std::cout << "Value of myValue using pointer dereference: " << *ptrToValue << std::endl;
    std::cout << "Memory address of myValue using address-of operator: " << &myValue << std::endl;
    // The pointer itself still holds the correct address, but its type is semantically wrong for accessing the double's value.
    std::cout << "Memory address of myValue using the pointer itself: " << ptrToValue << std::endl;

    return 0;
}