#include <iostream>
#include <vector> // This header is not strictly needed but often included

class ResourceHandler {
private:
    int* data_;
    size_t size_;

public:
    ResourceHandler(size_t s) : size_(s) {
        if (s > 0) {
            data_ = new int[s];
            for (size_t i = 0; i < s; ++i) {
                data_[i] = static_cast<int>(i * 10); // Initialize for testing
            }
            std::cout << "ResourceHandler created with array of size " << size_ << std::endl;
        } else {
            data_ = nullptr;
            std::cout << "ResourceHandler created with null array (size 0)." << std::endl;
        }
    }

    ~ResourceHandler() {
        if (data_ != nullptr) {
            delete[] data_;
            data_ = nullptr;
            std::cout << "ResourceHandler destroyed and memory deallocated." << std::endl;
        } else {
            std::cout << "ResourceHandler destroyed (no memory to deallocate)." << std::endl;
        }
    }

    // A simple getter for demonstration/testing
    int getElement(size_t index) const {
        if (data_ != nullptr && index < size_) {
            return data_[index];
        }
        return -1; // Indicate error or out of bounds
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    std::cout << "Starting program..." << std::endl;
    try {
        ResourceHandler handler(5);
        std::cout << "First element: " << handler.getElement(0) << std::endl;
        std::cout << "Last element: " << handler.getElement(4) << std::endl;

        ResourceHandler empty_handler(0);
        std::cout << "Empty handler element (should be -1): " << empty_handler.getElement(0) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "Program finished." << std::endl;
    return 0;
}