#include <iostream>
#include <cstring> // For strlen, strcpy

class ResourceLogger {
private:
    char* message; // Pointer to dynamically allocated C-style string

public:
    // Constructor: Dynamically allocates memory for the log message
    ResourceLogger(const char* msg) : message(nullptr) {
        if (msg == nullptr) {
            // Handle nullptr input gracefully by storing an empty string
            message = new char[1]; // Allocate minimum memory for null terminator
            message[0] = '\0';
            std::cout << "ResourceLogger created with an empty message (nullptr input handled)." << std::endl;
        } else {
            size_t len = std::strlen(msg);
            message = new char[len + 1]; // Allocate enough memory for message + null terminator
            std::strcpy(message, msg);   // Copy the message
            std::cout << "ResourceLogger created with message: " << message << std::endl;
        }
    }

    // Destructor: Deallocates the dynamically allocated memory
    ~ResourceLogger() {
        // It's safe to call delete[] on a nullptr, but an explicit check can be shown for clarity.
        if (message != nullptr) { 
            std::cout << "Resource freed: " << message << std::endl;
            delete[] message; // Deallocate the array
            message = nullptr; // Good practice: nullify the pointer after deletion
        }
    }

    // Rule of Three/Five: For a class managing raw pointers,
    // copy constructor and copy assignment operator should be defined, deleted, or defaulted.
    // Deleting them prevents accidental shallow copies that would lead to double-frees
    // when objects are copied, ensuring robust resource management.
    ResourceLogger(const ResourceLogger&) = delete;
    ResourceLogger& operator=(const ResourceLogger&) = delete;
};

int main() {
    std::cout << "Entering main scope..." << std::endl;

    // Demonstrate usage with a valid message
    ResourceLogger logger1("Hello, this is a valid log message.");

    { // Create another object in a nested scope to show immediate destruction
        ResourceLogger logger2("This message will be freed when exiting its scope.");
        std::cout << "Inside nested scope." << std::endl;
    } // logger2 goes out of scope here, its destructor is called

    // Demonstrate usage with a nullptr message, which is handled gracefully
    ResourceLogger logger3(nullptr);

    std::cout << "Exiting main scope..." << std::endl;
    return 0;
}