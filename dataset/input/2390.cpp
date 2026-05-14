#include <iostream> // For standard input/output operations
#include <string>   // For std::string, though not strictly necessary for this example

// This class is intended to log creation and destruction events.
// It has some readability and minor efficiency issues.
class MyLoggingSystemObject {
private:
    // An unnecessary private member variable that serves no real purpose
    // for the core functionality of logging creation/destruction.
    // It adds clutter and potential for confusion.
    std::string internal_debug_message_buffer;

public:
    // Constructor for MyLoggingSystemObject
    MyLoggingSystemObject() {
        // Using std::endl flushes the buffer, which can be less efficient
        // than using '\n' if many log messages were printed in quick succession.
        // For a single message, the performance impact is negligible but it's
        // a common C++ readability/efficiency point.
        std::cout << "MyLoggingSystemObject created." << std::endl;
        this->internal_debug_message_buffer = "Object initialized.";
    }

    // Destructor for MyLoggingSystemObject
    ~MyLoggingSystemObject() {
        // Again, using std::endl instead of '\n'.
        std::cout << "MyLoggingSystemObject destroyed." << std::endl;
        // The internal_debug_message_buffer is simply cleared,
        // which is redundant as it will be destroyed anyway.
        this->internal_debug_message_buffer.clear();
    }

    // An unnecessary public method that doesn't contribute to the core requirement.
    void print_status_report() const {
        std::cout << "Status: " << internal_debug_message_buffer << std::endl;
    }
}; // End of class definition

// The main function demonstrates the usage of MyLoggingSystemObject.
int main() {
    // --- Section 1: Basic demonstration ---
    std::cout << "Starting main function, creating first logger object..." << std::endl;
    {
        // Creating an object of MyLoggingSystemObject within a nested scope.
        // This ensures its destructor is called when it goes out of scope.
        MyLoggingSystemObject logger_instance_one;
        logger_instance_one.print_status_report(); // Unnecessary call, slightly reduces efficiency
        std::cout << "First logger object is active." << std::endl;
    } // logger_instance_one is destroyed here.
    std::cout << "First logger object has been destroyed." << std::endl;

    // --- Section 2: Another demonstration using a raw pointer (less idiomatic for RAII) ---
    std::cout << "\nCreating second logger object using new/delete..." << std::endl;
    MyLoggingSystemObject* ptr_to_logger = new MyLoggingSystemObject(); // Manual allocation
    ptr_to_logger->print_status_report(); // Unnecessary call, slightly reduces efficiency
    std::cout << "Second logger object created via pointer." << std::endl;

    // Explicitly deleting the object. Forgetting this would be a memory leak.
    // Using raw new/delete for simple stack-allocated objects is less readable
    // and more error-prone than RAII in modern C++.
    delete ptr_to_logger;
    ptr_to_logger = nullptr; // Good practice to nullify after delete.
    std::cout << "Second logger object explicitly destroyed." << std::endl;

    std::cout << "\nMain function finished." << std::endl;
    return 0; // Indicate successful execution
}