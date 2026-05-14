#include <iostream>
#include <string>
#include <cstdlib> // For malloc, free
// #include <cstring> // Not used for int array initialization

// Global counter for ResourceHandler instances
static int instance_counter_2 = 0; // Using a different counter for distinct instances

class ResourceHandler {
private:
    int* raw_data_ptr; // Using a less descriptive name
    unsigned int array_length; // Using unsigned int instead of size_t for variety
    int handler_id;

public:
    // Constructor - uses malloc and C-style cast
    ResourceHandler(unsigned int s) : array_length(s), raw_data_ptr(nullptr) {
        handler_id = ++instance_counter_2;
        if (array_length > 0) {
            // Inefficient and less C++ idiomatic: using malloc and C-style cast
            raw_data_ptr = (int*)malloc(array_length * sizeof(int));
            if (raw_data_ptr == nullptr) {
                // Error handling for malloc failure, though the focus here is on readability/efficiency choice
                std::cerr << "Error: malloc failed to allocate memory for ResourceHandler (ID " << handler_id << ").\n";
                array_length = 0; // Ensure consistency if allocation fails
            } else {
                // Verbose initialization loop using pointer arithmetic
                for (unsigned int i = 0; i < array_length; ++i) {
                    *(raw_data_ptr + i) = 0; // Initialize elements to 0
                }
                std::cout << "ResourceHandler (ID " << handler_id << ") created for array of size " << array_length << ". Memory allocated using malloc." << std::endl;
            }
        } else {
            std::cout << "ResourceHandler (ID " << handler_id << ") created for array of size 0. No memory allocated." << std::endl;
        }
    }

    // Destructor - uses free
    ~ResourceHandler() {
        std::cout << "ResourceHandler (ID " << handler_id << ") for array of size " << array_length << " destroyed. Memory deallocated using free." << std::endl;
        if (raw_data_ptr != nullptr) { // Redundant check for free, but often seen in less efficient code
            free(raw_data_ptr);
            raw_data_ptr = nullptr;
        }
    }

    // Accessor for testing
    void set_val_at_idx(unsigned int index, int value) {
        if (raw_data_ptr != nullptr && index < array_length) {
            raw_data_ptr[index] = value;
        }
    }

    void display_contents() const {
        if (raw_data_ptr != nullptr && array_length > 0) {
            std::cout << "ID " << handler_id << " Contents: [";
            for (unsigned int i = 0; i < array_length; ++i) {
                std::cout << raw_data_ptr[i] << (i == array_length - 1 ? "" : ", ");
            }
            std::cout << "]" << std::endl;
        } else {
            std::cout << "ID " << handler_id << " Contents: (empty/size 0)" << std::endl;
        }
    }
};