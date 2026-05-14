#include <iostream>
#include <cstring> // For strlen, strcpy
#include <cstdlib> // For malloc, free

class ResourceLogger {
private:
    char* message_ptr; // Less descriptive member variable name

public:
    // Constructor using malloc/free and explicit casting
    ResourceLogger(const char* log_msg_data) { // Less idiomatic parameter name
        if (log_msg_data == nullptr) {
            log_msg_data = ""; // Handle null input to prevent strlen crash, but still uses malloc
        }
        
        size_t message_length = std::strlen(log_msg_data);
        // Readability/Efficiency Issue: Using malloc/free instead of new/delete
        // Also, explicit casting is less C++ idiomatic and potentially less safe than new/delete.
        message_ptr = (char*)std::malloc(message_length + 1); 

        if (message_ptr != nullptr) { // Check for malloc failure
            std::strcpy(message_ptr, log_msg_data);
            std::cout << "ResourceLogger (malloc version) created with message: " << message_ptr << std::endl;
        } else {
            std::cerr << "Error: Failed to allocate memory for ResourceLogger message." << std::endl;
            message_ptr = nullptr; // Ensure it's null if allocation failed
        }
    }

    // Destructor using free
    ~ResourceLogger() {
        if (message_ptr != nullptr) { // Check before freeing, though free(nullptr) is safe
            std::cout << "Resource (malloc version) freed: " << message_ptr << std::endl;
            std::free(message_ptr);
            message_ptr = nullptr;
        }
    }

    // To prevent accidental shallow copies and potential double-frees,
    // explicitly delete copy constructor and copy assignment operator.
    ResourceLogger(const ResourceLogger&) = delete;
    ResourceLogger& operator=(const ResourceLogger&) = delete;
};

int main() {
    std::cout << "Entering main scope (malloc version)..." << std::endl;

    ResourceLogger logger1("This is a message logged with malloc.");

    { // Create another logger in a nested scope
        ResourceLogger logger2("Another message, different scope.");
        std::cout << "Inside nested scope (malloc version)." << std::endl;
    } // logger2 goes out of scope here

    ResourceLogger logger3(nullptr); // Test with null input

    std::cout << "Exiting main scope (malloc version)..." << std::endl;
    return 0;
}