#include <iostream>
#include <string>

// Global counter for ResourceHandler instances to make destruction messages unique.
static int instance_counter = 0;

class ResourceHandler {
private:
    int* data;
    size_t array_size;
    int instance_id; // To differentiate instances in destructor messages

public:
    // Constructor
    ResourceHandler(size_t s) : array_size(s), data(nullptr) {
        instance_id = ++instance_counter;
        if (array_size > 0) {
            data = new int[array_size];
            for (size_t i = 0; i < array_size; ++i) {
                data[i] = 0; // Initialize elements
            }
            std::cout << "ResourceHandler (ID " << instance_id << ") created for array of size " << array_size << ". Memory allocated." << std::endl;
        } else {
            std::cout << "ResourceHandler (ID " << instance_id << ") created for array of size 0. No memory allocated." << std::endl;
        }
    }

    // Destructor
    ~ResourceHandler() {
        std::cout << "ResourceHandler (ID " << instance_id << ") for array of size " << array_size << " destroyed. Memory deallocated." << std::endl;
        delete[] data; // This will be called twice for copied objects due to shallow copy
        data = nullptr; // Good practice
    }

    // No user-defined copy constructor or copy assignment operator.
    // The compiler-generated ones will perform a shallow copy, leading to double-free.

    // For testing purposes, let's add a method to verify memory access before destruction
    void fill_data(int start_val) {
        if (data) {
            for (size_t i = 0; i < array_size; ++i) {
                data[i] = start_val + i;
            }
        }
    }

    void print_data() const {
        if (data) {
            std::cout << "ID " << instance_id << " Data: [";
            for (size_t i = 0; i < array_size; ++i) {
                std::cout << data[i] << (i == array_size - 1 ? "" : ", ");
            }
            std::cout << "]" << std::endl;
        } else {
            std::cout << "ID " << instance_id << " Data: (empty/size 0)" << std::endl;
        }
    }
};