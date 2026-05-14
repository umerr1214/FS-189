#include <iostream>
#include <cstring> // For strlen, strcpy, etc.

class StringWrapper {
private:
    char* str;

public:
    // Default constructor
    StringWrapper(const char* s = nullptr) : str(nullptr) {
        if (s != nullptr) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }

    // Shallow Copy Constructor (Logical Error)
    StringWrapper(const StringWrapper& other) : str(other.str) { // Shallow copy: just copies the pointer
        // This is a logical error. It copies the pointer to the char array,
        // but does not allocate new memory or copy the content.
        // Both objects will point to the same memory location.
        // This leads to a double-free error when objects are destructed.
    }

    // Destructor
    ~StringWrapper() {
        delete[] str; // This will cause double-free because s1 and s2 point to the same memory
    }

    // Setter for modification (for testing independence)
    void setStr(const char* s) {
        delete[] str; // Free old memory
        str = nullptr;
        if (s != nullptr) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }

    // Getter
    const char* getStr() const {
        return str;
    }

    // Display for testing
    void display() const {
        if (str) {
            std::cout << "String: \"" << str << "\"" << std::endl;
        } else {
            std::cout << "String: (nullptr)" << std::endl;
        }
    }
};

int main() {
    StringWrapper s1("Hello, Shallow Copy!");
    std::cout << "s1: "; s1.display();

    StringWrapper s2 = s1; // Calls shallow copy constructor
    std::cout << "s2 (copy of s1): "; s2.display();

    std::cout << "\nModifying s1..." << std::endl;
    s1.setStr("Modified String 1"); // s1 frees its old memory, then allocates new.
                                     // s2.str still points to the *freed* memory, leading to dangling pointer.
    std::cout << "s1 after modification: "; s1.display();
    std::cout << "s2 after s1 modification: "; s2.display(); // Accessing s2.str here will result in undefined behavior.

    StringWrapper s3("Another one");
    std::cout << "s3: "; s3.display();

    StringWrapper s4; // Default constructor
    std::cout << "s4: "; s4.display();
    
    std::cout << "\nEnd of main." << std::endl;
    return 0; // Double-free will likely occur here as s1 and s2 destruct.
}