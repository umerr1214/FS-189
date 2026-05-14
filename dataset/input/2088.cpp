#include <iostream>
#include <cstring> // For strlen and strcpy

class ResourceLogger {
public:
    char* message;

    ResourceLogger(const char* msg) {
        std::cout << "ResourceLogger constructor called with: " << msg << std::endl;
        message = new char[std::strlen(msg) + 1];
        std::strcpy(message, msg);
    }

    // Semantic Error: No copy constructor or copy assignment operator defined.
    // The default compiler-generated ones perform a shallow copy of 'message'.
    // This means multiple ResourceLogger objects can point to the same dynamically allocated memory.

    ~ResourceLogger() {
        std::cout << "ResourceLogger destructor called. Freeing resource: " << message << std::endl;
        delete[] message; // This will lead to a double-free if objects are copied
        message = nullptr;
    }
};

void func(ResourceLogger logger_param) { // Pass by value, triggers copy constructor (shallow copy)
    std::cout << "Inside func with: " << logger_param.message << std::endl;
}

int main() {
    std::cout << "Entering main scope." << std::endl;
    {
        ResourceLogger originalLogger("Original message");
        std::cout << "Original message: " << originalLogger.message << std::endl;

        // Semantic Error: Shallow copy occurs here
        // originalLogger and copiedLogger now point to the same memory for 'message'
        ResourceLogger copiedLogger = originalLogger;
        std::cout << "Copied message: " << copiedLogger.message << std::endl;

        // When copiedLogger goes out of scope, it frees the memory.
        // When originalLogger goes out of scope, it tries to free the SAME memory again (double-free).
    } // copiedLogger and originalLogger go out of scope here
    std::cout << "Exiting inner scope." << std::endl;

    ResourceLogger anotherLogger("Another message for func");
    func(anotherLogger); // Pass by value, triggers copy constructor (shallow copy)
    std::cout << "After func call." << std::endl;

    // anotherLogger also goes out of scope here, leading to another potential double-free
    // if 'func' already freed its copy.

    std::cout << "Exiting main scope." << std::endl;
    return 0;
}