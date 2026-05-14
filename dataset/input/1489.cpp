#include <iostream>
#include <cstring> // Required for strcpy

// This Logger class demonstrates a robustness issue related to resource management
// when default copy constructor/assignment operator are implicitly used with a raw pointer member.
class Logger {
public:
    char* message_buffer; // A raw pointer to dynamically allocated memory

    Logger() {
        // Allocate memory for the initialization message.
        message_buffer = new char[50];
        std::strcpy(message_buffer, "Logger initialized.");
        std::cout << message_buffer << std::endl;
    }

    // IMPORTANT: The default copy constructor and assignment operator (implicitly generated)
    // will perform a shallow copy of 'message_buffer'. This means if a Logger object is copied,
    // both the original and the copy's 'message_buffer' will point to the same memory location.

    ~Logger() {
        // Prepare the destruction message. We need a temporary buffer because
        // message_buffer might already be invalid due to a previous deletion (double-free scenario).
        char destroy_msg[50];
        std::strcpy(destroy_msg, "Logger destroyed.");
        std::cout << destroy_msg << std::endl;

        // This delete[] operation is the source of the robustness issue.
        // If this Logger object was a shallow copy, 'message_buffer' points to memory
        // that another Logger object (the original) also points to. When both go out of scope,
        // they will attempt to delete the same memory twice, leading to undefined behavior
        // (often a crash due to double-free).
        delete[] message_buffer;
    }
};

// This function demonstrates the robustness issue by creating a copy of a Logger object.
void create_and_copy_logger_robustness() {
    Logger logger1; // Constructor called. message_buffer points to allocated memory.
    Logger logger2 = logger1; // Default copy constructor: logger2.message_buffer now points to the *same* memory as logger1.message_buffer.

    // When logger2 goes out of scope, its destructor is called, deleting message_buffer.
    // When logger1 then goes out of scope, its destructor is called, attempting to delete
    // the *same* message_buffer again, leading to a double-free.
}

int main() {
    std::cout << "--- Main Scope Start ---" << std::endl;

    Logger main_logger; // Constructor called.

    {
        std::cout << "--- Inner Scope Start ---" << std::endl;
        Logger block_logger; // Constructor called.
        std::cout << "--- Inner Scope End ---" << std::endl;
    } // block_logger destroyed.

    std::cout << "--- Calling function with copy ---" << std::endl;
    create_and_copy_logger_robustness(); // This function call will trigger the double-free.

    std::cout << "--- Main Scope End ---" << std::endl;
    return 0;
} // main_logger destroyed.