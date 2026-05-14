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
                data_[i] = static_cast<int>(i * 100); // Initialize for testing
            }
            std::cout << "ResourceHandler created with array of size " << size_ << " at address " << static_cast<void*>(data_) << std::endl;
        } else {
            data_ = nullptr;
            std::cout << "ResourceHandler created with null array (size 0)." << std::endl;
        }
    }

    ~ResourceHandler() {
        if (data_ != nullptr) {
            delete[] data_;
            data_ = nullptr;
            std::cout << "ResourceHandler destroyed. Memory at " << static_cast<void*>(data_) << " deallocated." << std::endl;
        } else {
            std::cout << "ResourceHandler destroyed (no memory to deallocate)." << std::endl;
        }
    }

    // SEMANTIC ERROR: Missing copy constructor and copy assignment operator.
    // The default copy constructor performs a shallow copy, leading to
    // multiple ResourceHandler objects owning the same raw pointer 'data_'.

    int getElement(size_t index) const {
        if (data_ == nullptr || index >= size_) {
            throw std::out_of_range("Index out of bounds or array is null.");
        }
        return data_[index];
    }
};

int main() {
    std::cout << "Starting program with semantic error test (Rule of Three violation)..." << std::endl;
    try {
        ResourceHandler handler1(5); // Original object
        std::cout << "handler1 element at index 2: " << handler1.getElement(2) << std::endl;

        // Creating a copy without a proper copy constructor
        // This causes handler2.data_ to point to the same memory as handler1.data_
        ResourceHandler handler2 = handler1; // Default copy constructor called
        std::cout << "handler2 element at index 2: " << handler2.getElement(2) << std::endl;

        // When handler2 goes out of scope, its destructor will delete[] data_.
        // When handler1 goes out of scope, its destructor will attempt to delete[] the SAME data_,
        // leading to a double-free and undefined behavior (likely a crash).

    } catch (const std::out_of_range& e) {
        std::cerr << "Caught out_of_range exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught generic exception: " << e.what() << std::endl;
    }
    std::cout << "Program finished (or crashed due to double-free)." << std::endl;
    return 0;
}