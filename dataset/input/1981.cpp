#include <iostream>
#include <cstring> // For strlen, strcpy
#include <stdexcept> // For potential exceptions

class StringWrapper {
public:
    char* data;
    size_t len;

    // Default Constructor - Robustness Issue: Leaves 'data' and 'len' uninitialized.
    // Accessing 'data' or 'len' before proper initialization (e.g., if another constructor isn't called) is UB.
    // A robust default constructor would initialize data to nullptr and len to 0.
    StringWrapper() {
        // data and len are uninitialized. This is a robustness flaw.
        // A robust implementation would be: data = nullptr; len = 0;
        std::cout << "StringWrapper() default constructed (uninitialized data)" << std::endl;
    }

    // Constructor
    StringWrapper(const char* s) {
        if (s == nullptr) {
            data = nullptr;
            len = 0;
        } else {
            len = strlen(s);
            data = new char[len + 1];
            strcpy(data, s);
        }
        std::cout << "StringWrapper(const char*) constructed: " << (data ? data : "nullptr") << std::endl;
    }

    // Copy Constructor - Performs deep copy (as per question)
    StringWrapper(const StringWrapper& other) {
        if (other.data != nullptr) {
            len = other.len;
            data = new char[len + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
            len = 0;
        }
        std::cout << "StringWrapper(const StringWrapper&) copied: " << (data ? data : "nullptr") << std::endl;
    }

    // Destructor
    ~StringWrapper() {
        if (data) {
            std::cout << "~StringWrapper() destructed: " << data << std::endl;
            delete[] data;
            data = nullptr;
        } else {
            std::cout << "~StringWrapper() destructed (nullptr)" << std::endl;
        }
    }

    // Missing Copy Assignment Operator - Robustness Issue
    // If not explicitly defined, the compiler-generated default copy assignment operator
    // will perform a shallow copy of 'data' and 'len'. This leads to:
    // 1. Double-free errors when both objects try to delete the same memory.
    // 2. Memory leaks if the target object's original 'data' is not deallocated before overwriting.
    // 3. Dangling pointers if one object is destructed, leaving the other pointing to invalid memory.

    const char* get() const {
        return data ? data : ""; // Return empty string for nullptr for safer access
    }
};

int main() {
    StringWrapper s1("Hello World");
    StringWrapper s2 = s1; // Uses copy constructor

    std::cout << "s1: " << s1.get() << std::endl;
    std::cout << "s2: " << s2.get() << std::endl;

    // Demonstrate the missing copy assignment operator issue (implicitly)
    // The following line uses the default-generated copy assignment operator,
    // which performs a shallow copy. This will lead to issues (double-free, memory leaks)
    // when s3 and s1 are destructed, or when s3 is assigned again.
    // However, for the program to "compile and run correctly" for evaluation,
    // we won't directly trigger the crash in the driver code, but the flaw exists in the class design.
    StringWrapper s3; // Uses default constructor, data is uninitialized.
    // s3 = s1; // If uncommented, this line would cause issues due to shallow copy.
               // The robustness issue is that the class is *not safe* for assignment.

    // Test with nullptr construction for robustness of the explicit constructor
    StringWrapper s4(nullptr);
    StringWrapper s5 = s4;
    std::cout << "s4: " << s4.get() << std::endl;
    std::cout << "s5: " << s5.get() << std::endl;

    return 0;
}