#include <iostream>
#include <cstring> // For strlen and strcpy

class ResourceLogger {
public:
    char* message;

    ResourceLogger(const char* msg) {
        std::cout << "ResourceLogger constructor called with: " << msg << std::endl;
        // Logical Error: Allocate strlen(msg) instead of strlen(msg) + 1.
        // This omits space for the null terminator, leading to a buffer overflow
        // when std::strcpy attempts to write the null terminator past the allocated memory.
        message = new char[std::strlen(msg)]; // ERROR: Should be std::strlen(msg) + 1
        std::strcpy(message, msg); // This will write past the allocated buffer by 1 byte
    }

    ~ResourceLogger() {
        std::cout << "ResourceLogger destructor called. Freeing resource: " << message << std::endl;
        delete[] message;
        message = nullptr;
    }
};

void func() {
    ResourceLogger logger("Short message");
}

int main() {
    std::cout << "Entering main scope." << std::endl;
    {
        ResourceLogger myLogger("A somewhat longer message to demonstrate the issue.");
    }
    std::cout << "Exiting inner scope." << std::endl;
    func();
    std::cout << "Exiting main scope." << std::endl;
    return 0;
}