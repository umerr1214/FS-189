#include <iostream>

class Resource {
private:
    int* data;
    int size;

public:
    // Constructor
    Resource(int s) : size(s) {
        if (s <= 0) {
            data = nullptr;
            size = 0;
            std::cerr << "Warning: Resource size must be positive. Initializing with size 0." << std::endl;
        } else {
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = 0; // Initialize with zeros
            }
        }
    }

    // Destructor
    ~Resource() {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
        std::cout << "Resource of size " << size << " deallocated." << std::endl;
    }

    // Fills the array with values (e.g., i+1)
    void fillArray() {
        if (data == nullptr) {
            std::cerr << "Error: Cannot fill an uninitialized array." << std::endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            data[i] = i + 1;
        }
        std::cout << "Array filled." << std::endl;
    }

    // Displays the array elements - LOGICAL ERROR HERE
    void displayArray() const {
        if (data == nullptr) {
            std::cout << "Array is empty or uninitialized." << std::endl;
            return;
        }
        std::cout << "Array elements: ";
        // LOGICAL ERROR: The loop iterates up to size - 1, missing the last element (data[size-1])
        for (int i = 0; i < size - 1; ++i) { 
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    int getSize() const {
        return size;
    }
};

int main() {
    std::cout << "--- Resource Lifecycle Demonstration (Logical Error) ---" << std::endl;
    {
        Resource res(5);
        if (res.getSize() > 0) {
            res.fillArray();
            res.displayArray(); // Will display 4 elements instead of 5
        }
    } // Destructor called here
    std::cout << "--- End of demonstration ---" << std::endl;
    return 0;
}