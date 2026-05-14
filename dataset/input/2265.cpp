#include <iostream>
#include <string>
#include <algorithm> // For std::copy and std::swap
#include <utility>   // For std::move

// Global counter for ResourceHandler instances
static int instance_counter_3 = 0;

class ResourceHandler {
private:
    int* data;
    size_t array_size;
    int instance_id;

    // Helper to deallocate memory
    void cleanup() {
        delete[] data;
        data = nullptr;
    }

public:
    // Constructor
    ResourceHandler(size_t s) : array_size(s), data(nullptr) {
        instance_id = ++instance_counter_3;
        if (array_size > 0) {
            data = new int[array_size];
            for (size_t i = 0; i < array_size; ++i) {
                data[i] = 0; // Initialize elements to 0
            }
            std::cout << "ResourceHandler (ID " << instance_id << ") created for array of size " << array_size << ". Memory allocated." << std::endl;
        } else {
            std::cout << "ResourceHandler (ID " << instance_id << ") created for array of size 0. No memory allocated." << std::endl;
        }
    }

    // Destructor
    ~ResourceHandler() {
        std::cout << "ResourceHandler (ID " << instance_id << ") for array of size " << array_size << " destroyed. Memory deallocated." << std::endl;
        cleanup();
    }

    // Copy Constructor (Deep Copy)
    ResourceHandler(const ResourceHandler& other) : array_size(other.array_size), data(nullptr) {
        instance_id = ++instance_counter_3; // New instance gets a new ID
        if (array_size > 0) {
            data = new int[array_size];
            std::copy(other.data, other.data + array_size, data); // Deep copy elements
            std::cout << "ResourceHandler (ID " << instance_id << ") copy constructed from ID " << other.instance_id << " for array of size " << array_size << ". Memory allocated." << std::endl;
        } else {
            std::cout << "ResourceHandler (ID " << instance_id << ") copy constructed from ID " << other.instance_id << " for array of size 0. No memory allocated." << std::endl;
        }
    }

    // Copy Assignment Operator (Deep Copy - Copy-and-Swap Idiom for strong exception safety)
    ResourceHandler& operator=(const ResourceHandler& other) {
        if (this != &other) { // Handle self-assignment
            ResourceHandler temp(other); // Create a temporary deep copy
            std::swap(data, temp.data);
            std::swap(array_size, temp.array_size);
            // instance_id remains the same for the assigned object
            std::cout << "ResourceHandler (ID " << instance_id << ") copy assigned from ID " << other.instance_id << ". Resources swapped." << std::endl;
        } else {
            std::cout << "ResourceHandler (ID " << instance_id << ") self-assignment detected." << std::endl;
        }
        return *this;
    }

    // Move Constructor
    ResourceHandler(ResourceHandler&& other) noexcept
        : data(other.data), array_size(other.array_size), instance_id(++instance_counter_3) { // New ID for the moved-to object
        other.data = nullptr; // Leave the moved-from object in a valid, empty state
        other.array_size = 0;
        std::cout << "ResourceHandler (ID " << instance_id << ") move constructed from ID " << other.instance_id << " (now empty)." << std::endl;
    }

    // Move Assignment Operator
    ResourceHandler& operator=(ResourceHandler&& other) noexcept {
        if (this != &other) { // Handle self-assignment
            std::cout << "ResourceHandler (ID " << instance_id << ") move assigned from ID " << other.instance_id << " (now empty)." << std::endl;
            cleanup(); // Deallocate existing resources
            data = other.data;
            array_size = other.array_size;
            // instance_id remains the same for the assigned object
            other.data = nullptr; // Leave moved-from object in valid, empty state
            other.array_size = 0;
        } else {
            std::cout << "ResourceHandler (ID " << instance_id << ") self-move assignment detected." << std::endl;
        }
        return *this;
    }

    // Accessor for testing
    void set_element(size_t index, int value) {
        if (data != nullptr && index < array_size) {
            data[index] = value;
        }
    }

    int get_element(size_t index) const {
        if (data != nullptr && index < array_size) {
            return data[index];
        }
        return -1; // Indicate error or out of bounds
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