#include <iostream>

class ResourceHandler {
private:
    int* data;
    size_t size;

public:
    ResourceHandler(size_t s) : size(s) {
        if (size > 0) {
            data = new int[size];
            std::cout << "ResourceHandler: Allocated memory for " << size << " integers." << std::endl;
        } else {
            data = nullptr;
            std::cout << "ResourceHandler: No memory allocated for size 0." << std::endl;
        }
    }

    ~ResourceHandler() {
        if (data != nullptr) {
            // Semantic Error: Using 'delete' instead of 'delete[]' for an array allocated with 'new int[size]'.
            // This leads to undefined behavior, potential memory leaks, or heap corruption.
            delete data; // Should be delete[] data;
            std::cout << "ResourceHandler: Deallocated memory (incorrectly)." << std::endl;
        } else {
            std::cout << "ResourceHandler: No memory to deallocate." << std::endl;
        }
    }

    void fillData() {
        if (data) {
            for (size_t i = 0; i < size; ++i) {
                data[i] = i + 1;
            }
            std::cout << "ResourceHandler: Data filled." << std::endl;
        } else {
            std::cout << "ResourceHandler: Cannot fill data, no memory allocated." << std::endl;
        }
    }

    void printData() const {
        if (data) {
            std::cout << "ResourceHandler: Data: [";
            for (size_t i = 0; i < size; ++i) {
                std::cout << data[i] << (i == size - 1 ? "" : ", ");
            }
            std::cout << "]" << std::endl;
        } else {
            std::cout << "ResourceHandler: No data to print." << std::endl;
        }
    }
};

int main() {
    {
        ResourceHandler handler(5);
        handler.fillData();
        handler.printData();
    } // Destructor called here, triggering the semantic error
    std::cout << "Program finished." << std::endl;
    return 0;
}