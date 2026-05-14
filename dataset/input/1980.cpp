#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
private:
    char* data;

public:
    // Default constructor
    StringWrapper(const char* str = "") {
        if (str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Copy constructor (correct deep copy)
    StringWrapper(const StringWrapper& other) {
        if (other.data) {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Destructor (correct)
    ~StringWrapper() {
        delete[] data;
    }

    // SEMANTIC ERROR: Missing copy assignment operator
    // The compiler will generate a default shallow copy assignment operator.
    // When objects are assigned (e.g., s1 = s2), this default operator will
    // copy the 'data' pointer directly, leading to two StringWrapper objects
    // pointing to the same dynamically allocated memory. This causes a
    // double-free error when both objects are destroyed.

    // Accessor
    const char* get() const {
        return data;
    }

    // For testing/output
    void print() const {
        std::cout << "StringWrapper content: \"" << (data ? data : "(null)") << "\"" << std::endl;
    }
};

// Main function to test
int main() {
    std::cout << "--- StringWrapper Test (Semantic Error: Missing Assignment Operator) ---" << std::endl;

    // Test Case 1: Simple assignment to demonstrate the problem
    StringWrapper s1("First String");
    std::cout << "s1: "; s1.print(); // Expected: "First String"

    StringWrapper s2("Second String");
    std::cout << "s2: "; s2.print(); // Expected: "Second String"

    std::cout << "\nAssigning s1 = s2 (triggers shallow copy assignment)..." << std::endl;
    s1 = s2; // Calls compiler-generated shallow copy assignment operator

    std::cout << "After assignment:" << std::endl;
    std::cout << "s1: "; s1.print(); // Actual: s1.data now points to s2.data's memory. Prints "Second String".
    std::cout << "s2: "; s2.print(); // Actual: s2.data still points to its memory. Prints "Second String".

    // The primary issue (double-free) occurs when s1 and s2 are destructed,
    // as they both attempt to delete the same memory pointed to by s2.data.

    std::cout << "\n--- Demonstrating Double Free Potential ---" << std::endl;
    { // Create a scope to ensure destructors are called
        StringWrapper a("Hello");
        StringWrapper b("World");
        std::cout << "Inside scope:" << std::endl;
        std::cout << "a: "; a.print();
        std::cout << "b: "; b.print();
        b = a; // Compiler-generated shallow copy assignment
        std::cout << "After b = a (shallow copy):" << std::endl;
        std::cout << "a: "; a.print();
        std::cout << "b: "; b.print(); // b.data now points to a.data's memory.
    } // 'a' is destroyed, frees "Hello". 'b' is destroyed, attempts to free "Hello" again -> double-free.

    std::cout << "\n--- End Test (Potential Double Free on Exit) ---" << std::endl;
    return 0;
}