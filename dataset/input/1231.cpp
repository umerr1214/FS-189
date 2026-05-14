#include <iostream>
#include <cstring> // For strlen, strcpy_s (on MSVC) or strcpy (less safe)
#include <stdexcept> // For potential exceptions

// A simple helper for strcpy_s on platforms where it's not standard
#ifdef _MSC_VER
#define STRCPY_S(dest, dest_size, src) strcpy_s(dest, dest_size, src)
#else
#define STRCPY_S(dest, dest_size, src) strncpy(dest, src, dest_size); dest[dest_size - 1] = '\0';
#endif

class StringWrapper {
private:
    char* data;

public:
    // Default and C-string constructor
    StringWrapper(const char* str = nullptr) : data(nullptr) {
        if (str) {
            size_t len = std::strlen(str);
            data = new char[len + 1];
            STRCPY_S(data, len + 1, str);
        } else {
            // Represent an empty string as a null-terminated empty buffer
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Deep Copy Constructor
    StringWrapper(const StringWrapper& other) : data(nullptr) {
        if (other.data) {
            size_t len = std::strlen(other.data);
            data = new char[len + 1];
            STRCPY_S(data, len + 1, other.data);
        } else {
            // Should not happen if other.data is always valid after construction
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
        data = nullptr; // Good practice to nullify pointer after deletion
    }

    // Getter for the C-style string
    const char* get() const {
        return data;
    }

    // Function to print the string
    void print(const char* prefix = "") const {
        std::cout << prefix << (data ? data : "(null)") << std::endl;
    }

    // *** ROBUSTNESS ISSUE: Missing Copy Assignment Operator ***
    // The default compiler-generated copy assignment operator will perform a shallow copy.
    // This means if s1 and s3 are StringWrapper objects, and you do s3 = s1,
    // both s1.data and s3.data will point to the same memory.
    // This will lead to double deletion when the objects are destroyed,
    // or incorrect behavior if one object modifies the shared memory.
};

int main() {
    // Test Case 1: Basic construction and copy constructor
    StringWrapper s1("Hello, World!");
    std::cout << "s1: ";
    s1.print();

    StringWrapper s2 = s1; // Calls copy constructor
    std::cout << "s2 (copy of s1): ";
    s2.print();

    // Test Case 2: Assignment operation - Triggers robustness issue
    // The default assignment operator will perform a shallow copy.
    // s3.data and s4.data will point to the same memory.
    StringWrapper s3("Initial string for s3");
    std::cout << "s3 (initial): ";
    s3.print();

    StringWrapper s4("Another string for s4");
    std::cout << "s4 (initial): ";
    s4.print();

    std::cout << "Assigning s4 = s3..." << std::endl;
    s4 = s3; // This uses the default shallow copy assignment operator
             // s4.data will now point to s3.data's memory.
             // The original memory of s4 ("Another string for s4") is leaked.
             // When s3 and s4 go out of scope, the same memory will be deleted twice.

    std::cout << "s3 (after assignment to s4): ";
    s3.print();
    std::cout << "s4 (after assignment from s3): ";
    s4.print();

    // The program might crash or exhibit undefined behavior upon exiting main
    // due to double-free of the memory pointed to by s3.data and s4.data.

    return 0;
}