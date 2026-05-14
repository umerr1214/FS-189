#include <iostream>
#include <stdexcept> // For std::out_of_range

class ResourceHandler {
private:
    int* data_;
    size_t size_;

public:
    ResourceHandler(size_t s) : size_(s) {
        if (s > 0) {
            data_ = new int[s];
            for (size_t i = 0; i < s; ++i) {
                data_[i] = static_cast<int>(i + 1); // Initialize for testing
            }
            std::cout << "ResourceHandler created with array of size " << size_ << std::endl;
        } else {
            data_ = nullptr;
            std::cout << "ResourceHandler created with null array (size 0)." << std::endl;
        }
    }

    ~ResourceHandler() {
        if (data_ != nullptr) {
            // LOGICAL ERROR: Using 'delete' instead of 'delete[]' for an array
            // This leads to undefined behavior, potential memory leaks, or corruption.
            delete data_;
            data_ = nullptr;
            std::cout << "ResourceHandler destroyed. Memory deallocated (logically incorrect for array)." << std::endl;
        } else {
            std::cout << "ResourceHandler destroyed (no memory to deallocate)." << std::endl;
        }
    }

    int getElement(size_t index) const {
        if (data_ == nullptr || index >= size_) {
            throw std::out_of_range("Index out of bounds or array is null.");
        }
        return data_[index];
    }
};

int main() {
    std::cout << "Starting program with logical error test..." << std::endl;
    try {
        ResourceHandler handler(10);
        std::cout << "Element at index 3: " << handler.getElement(3) << std::endl;
        std::cout << "Element at index 7: " << handler.getElement(7) << std::endl;

        // The logical error (incorrect deallocation) will occur when 'handler' goes out of scope.
        // It might not immediately crash but could lead to memory corruption or leaks.
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught out_of_range exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught generic exception: " << e.what() << std::endl;
    }
    std::cout << "Program finished." << std::endl;
    return 0;
}