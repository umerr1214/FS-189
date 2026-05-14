#include <iostream>
#include <cstring> // For strlen and strcpy

class ResourceLogger {
public:
    char* message;

    ResourceLogger(const char* msg) {
        std::cout << "ResourceLogger constructor called with: " << msg << std::endl;
        // Dynamically allocate memory for the message
        message = new char[std::strlen(msg) + 1];
        std::strcpy(message, msg);
    }

    ~ResourceLogger() {
        std::cout << "ResourceLogger destructor called. Freeing resource: " << message << std::endl;
        delete[] message; // Deallocate the C-style string
        message = nullptr; // Good practice
    }
};

void func() {
    ResourceLogger logger("Temporary log message");
}

int main() {
    std::cout << "Entering main scope." << std::endl
    { // Syntax Error: Missing semicolon after std::endl
        ResourceLogger myLogger("Main scope log message");
        // Object goes out of scope here
    }
    std::cout << "Exiting inner scope." << std::endl;
    func(); // Demonstrate another object going out of scope
    std::cout << "Exiting main scope." << std::endl;
    return 0;
}