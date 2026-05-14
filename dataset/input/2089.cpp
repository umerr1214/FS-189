#include <iostream>
#include <cstring> // For strlen, strcpy, strncpy

class ResourceLogger {
private:
    char* message;
    // Robustness Issue: Fixed-size buffer, potential buffer overflow
    // The class allocates a fixed small buffer regardless of the input message length.
    // If the input string is longer than BUFFER_SIZE - 1, it will be truncated.
    // In a real scenario, this could lead to buffer overflows if strncpy wasn't used
    // or if the null terminator was forgotten.
    static const int BUFFER_SIZE = 10; 

public:
    // Constructor
    ResourceLogger(const char* msg) : message(nullptr) {
        if (msg == nullptr) {
            msg = "(null_input)"; // Default message for null input
        }
        
        message = new char[BUFFER_SIZE];
        // Using strncpy to prevent a direct crash from overflow,
        // but it still demonstrates the truncation issue.
        std::strncpy(message, msg, BUFFER_SIZE - 1);
        message[BUFFER_SIZE - 1] = '\0'; // Ensure null termination

        std::cout << "ResourceLogger created with message: " << message << std::endl;
    }

    // Destructor
    ~ResourceLogger() {
        if (message != nullptr) {
            std::cout << "Resource freed: " << message << std::endl;
            delete[] message;
            message = nullptr; // Good practice to nullify after deletion
        }
    }

    // To prevent accidental shallow copies and potential double-frees,
    // explicitly delete copy constructor and copy assignment operator.
    ResourceLogger(const ResourceLogger&) = delete;
    ResourceLogger& operator=(const ResourceLogger&) = delete;
};

int main() {
    std::cout << "Entering main scope..." << std::endl;

    // This message "Hello World!" is longer than BUFFER_SIZE - 1 (9 characters).
    // It will be truncated to "Hello Wor".
    ResourceLogger logger1("Hello World!");

    { // Create another logger in a nested scope
        // This message "Short" is within the buffer size.
        ResourceLogger logger2("Short");
        std::cout << "Inside nested scope." << std::endl;
    } // logger2 goes out of scope here, its destructor is called

    // Test with a null message
    ResourceLogger logger3(nullptr);

    std::cout << "Exiting main scope..." << std::endl;
    return 0;
}