#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
public:
    char* data;
    size_t length;

    StringWrapper(const char* str = nullptr) {
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        } else {
            data = nullptr;
            length = 0;
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Copy Constructor - LOGICAL ERROR: Performs a shallow copy instead of a deep copy.
    // Both 'this->data' and 'other.data' will point to the same memory location.
    // This will lead to a double-free error when both objects are destroyed.
    StringWrapper(const StringWrapper& other) {
        this->data = other.data; // Shallow copy
        this->length = other.length;
    }

    void print() const {
        if (data) {
            std::cout << "String: \"" << data << "\", Length: " << length << std::endl;
        } else {
            std::cout << "String: (null), Length: " << length << std::endl;
        }
    }
};

int main() {
    std::cout << "--- Testing Shallow Copy (Logical Error) ---" << std::endl;

    StringWrapper s1("Hello");
    std::cout << "s1 created: ";
    s1.print(); // Expected: String: "Hello", Length: 5

    StringWrapper s2 = s1; // Copy constructor called (shallow copy)
    std::cout << "s2 copied from s1: ";
    s2.print(); // Expected: String: "Hello", Length: 5 (initially appears correct)

    // When s1 and s2 go out of scope, their destructors will both attempt to
    // delete the same `data` pointer, leading to a double-free runtime error.
    std::cout << "Objects s1 and s2 are about to go out of scope." << std::endl;
    std::cout << "Expect a runtime error (e.g., double-free or heap corruption)." << std::endl;

    return 0; // Program will likely crash here or just before exiting main
}