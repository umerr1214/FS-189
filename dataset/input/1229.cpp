#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
public:
    char* data;
    size_t length;

    // Default constructor
    StringWrapper(const char* str = "") {
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        } else {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Copy constructor - LOGICAL ERROR: Performs shallow copy
    StringWrapper(const StringWrapper& other) {
        // This is a shallow copy! Both data pointers will point to the same memory.
        // When one object is destroyed, it will free the memory, leading to
        // use-after-free or double-free when the other object is destroyed.
        this->data = other.data; // This is the error
        this->length = other.length;
    }

    // Helper to print string
    void print() const {
        std::cout << data << std::endl;
    }
};

int main() {
    // Test case 1: Basic copy
    std::cout << "--- Test 1: Basic Copy ---" << std::endl;
    StringWrapper s1("Hello, World!");
    std::cout << "s1 original: ";
    s1.print();

    StringWrapper s2 = s1; // Calls copy constructor (shallow copy)
    std::cout << "s2 (copy of s1): ";
    s2.print();

    std::cout << "\n--- Test 2: Scope and Deletion (expect crash/UB) ---" << std::endl;
    {
        StringWrapper temp1("First String");
        StringWrapper temp2 = temp1; // Shallow copy
        std::cout << "temp1: "; temp1.print();
        std::cout << "temp2: "; temp2.print();
    } // temp1 and temp2 destructors called here. This is where the double-free or use-after-free happens.

    std::cout << "\nProgram finished (if no crash occurred)." << std::endl;

    return 0;
}