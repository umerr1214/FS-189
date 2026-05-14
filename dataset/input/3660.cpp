#include <iostream>
#include <cstdint> // Required for uintptr_t

int main() {
    int myVar = 123;
    int* ptrToVar = &myVar; // Initially correctly declared and initialized

    // Semantic Error: The pointer 'ptrToVar' is reassigned to an arbitrary, invalid memory address.
    // This code compiles, but semantically, 'ptrToVar' no longer points to 'myVar' or any valid memory.
    // Dereferencing it later will result in undefined behavior (e.g., a crash or reading garbage).
    ptrToVar = reinterpret_cast<int*>(static_cast<uintptr_t>(0xDEADBEEF));

    std::cout << "Value of variable: " << myVar << std::endl;
    // This line attempts to dereference an invalid pointer, leading to undefined behavior.
    std::cout << "Value through pointer: " << *ptrToVar << std::endl;
    std::cout << "Address of variable: " << &myVar << std::endl;
    // The address of the pointer variable 'ptrToVar' itself is still valid.
    std::cout << "Address of pointer: " << &ptrToVar << std::endl;

    return 0;
}