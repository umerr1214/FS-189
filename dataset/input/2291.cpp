#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    StringWrapper() : data(nullptr), length(0) {
        data = new char[1];
        data[0] = '\0';
    }

    // Constructor with const char*
    StringWrapper(const char* str) {
        if (str == nullptr) {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        }
    }

    // Destructor
    ~StringWrapper() {
        std::cout << "Destructor for: \"" << (data ? data : "") << "\" (addr: " << static_cast<void*>(data) << ")" << std::endl;
        delete[] data;
    }

    // Copy constructor (LOGICAL ERROR: Performs a shallow copy)
    StringWrapper(const StringWrapper& other) : data(other.data), length(other.length) {
        // This performs a shallow copy: 'data' points to the same memory as 'other.data'.
        // This violates the requirement for independent memory management.
        // It will lead to issues like:
        // 1. Modifying 'other' will also modify 'this' (and vice versa).
        // 2. Double-freeing the same memory when both objects are destructed.
        std::cout << "Shallow copy constructor called. Data shared: " << static_cast<void*>(data) << std::endl;
    }

    // Assignment operator (correctly implemented deep copy for comparison)
    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data; // Free existing memory
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        return *this;
    }

    // Assignment operator from const char*
    StringWrapper& operator=(const char* str) {
        delete[] data;
        if (str == nullptr) {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        }
        return *this;
    }

    // Getter for string data
    const char* get() const {
        return data;
    }

    size_t size() const {
        return length;
    }

    void print() const {
        std::cout << "String: \"" << (data ? data : "") << "\" (Length: " << length << ", Addr: " << static_cast<void*>(data) << ")" << std::endl;
    }

    // Method to modify the string for testing shallow copy effects
    void modify(const char* new_str) {
        std::cout << "Modifying string from \"" << (data ? data : "") << "\" to \"" << (new_str ? new_str : "") << "\"" << std::endl;
        delete[] data;
        if (new_str == nullptr) {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            length = std::strlen(new_str);
            data = new char[length + 1];
            std::strcpy(data, new_str);
        }
    }
};

int main() {
    std::cout << "--- Test 1: Original and Shallow Copy ---" << std::endl;
    StringWrapper s1("Hello");
    std::cout << "s1: "; s1.print();

    StringWrapper s2 = s1; // Calls the shallow copy constructor
    std::cout << "s2 (copy of s1): "; s2.print(); // Initially looks correct, but shares memory

    std::cout << "\n--- Test 2: Modifying Original (Reveals Shallow Copy) ---" << std::endl;
    s1.modify("World");
    std::cout << "s1 after modification: "; s1.print();
    std::cout << "s2 after s1 modification: "; s2.print(); // LOGICAL ERROR: s2's content also changed!

    std::cout << "\n--- Test 3: Demonstrating Double Free (expected runtime error) ---" << std::endl;
    {
        StringWrapper s3("Temporary");
        std::cout << "s3: "; s3.print();
        StringWrapper s4 = s3; // Another shallow copy
        std::cout << "s4 (copy of s3): "; s4.print();
        // When s3 and s4 go out of scope, they will both attempt to delete the same memory,
        // leading to a double-free error and program crash.
    } // s3 and s4 destructors called here, leading to potential crash.

    std::cout << "\nProgram finished. Expect a crash or undefined behavior from double-free." << std::endl;

    return 0;
}