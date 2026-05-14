#include <iostream>

// Syntax Error: Missing semicolon after class definition
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
            delete[] data;
            std::cout << "ResourceHandler: Deallocated memory." << std::endl;
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
} // Missing semicolon here

int main() {
    {
        ResourceHandler handler(5);
        handler.fillData();
    } // handler goes out of scope, destructor called
    std::cout << "Program finished." << std::endl;
    return 0;
}