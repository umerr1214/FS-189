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
        // Logical Error: The message "Deallocated memory." is printed unconditionally
        // even if 'data' was nullptr and no actual deallocation occurred.
        delete[] data; // This is safe for nullptr, but the message is misleading
        std::cout << "ResourceHandler: Deallocated memory." << std::endl;
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
};

int main() {
    {
        ResourceHandler handler1(5);
        handler1.fillData();
    }
    std::cout << "--- Test Case Separator ---" << std::endl;
    {
        ResourceHandler handler2(0); // This will trigger the logical error in the destructor's message
    }
    std::cout << "Program finished." << std::endl;
    return 0;
}