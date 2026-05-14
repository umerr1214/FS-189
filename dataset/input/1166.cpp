#include <iostream>
#include <cstring> // For strlen, strcpy
#include <algorithm> // Not strictly needed for this version

class StringWrapper {
private:
    char* m_str;

public:
    // Default constructor
    StringWrapper() : m_str(nullptr) {}

    // Constructor with C-style string
    StringWrapper(const char* s) : m_str(nullptr) {
        if (s) {
            m_str = new char[strlen(s) + 1];
            strcpy(m_str, s);
        }
    }

    // Copy constructor
    StringWrapper(const StringWrapper& other) : m_str(nullptr) {
        if (other.m_str) {
            m_str = new char[strlen(other.m_str) + 1];
            strcpy(m_str, other.m_str);
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] m_str;
        m_str = nullptr;
    }

    // Getter for the string
    const char* getString() const {
        return m_str ? m_str : "";
    }

    // Readability / Efficiency Issue: Correct but verbose manual resource management.
    // This implementation is correct and handles all cases (self-assignment, empty strings)
    // but it is more verbose and less idiomatic/exception-safe compared to the copy-and-swap idiom.
    // It manually deallocates and reallocates memory, which can be less efficient
    // or harder to maintain than delegating to the copy constructor and destructor.
    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        // Deallocate old memory
        delete[] m_str;
        m_str = nullptr; // Defensive

        // Allocate new memory and copy
        if (other.m_str) {
            m_str = new char[strlen(other.m_str) + 1];
            strcpy(m_str, other.m_str);
        } else {
            m_str = nullptr; // Assign to nullptr if other is empty
        }

        return *this;
    }
};

// Driver code
int main() {
    StringWrapper s1("Hello");
    StringWrapper s2("World");
    StringWrapper s3; // m_str is nullptr
    StringWrapper s4("C++");
    StringWrapper s5("Programming");

    std::cout << "Initial States:" << std::endl;
    std::cout << "s1: " << s1.getString() << std::endl;
    std::cout << "s2: " << s2.getString() << std::endl;
    std::cout << "s3: " << s3.getString() << std::endl;
    std::cout << "s4: " << s4.getString() << std::endl;
    std::cout << "s5: " << s5.getString() << std::endl;

    std::cout << "\n--- Test 1: s1 = s2 (basic assignment) ---" << std::endl;
    s1 = s2;
    std::cout << "s1: " << s1.getString() << std::endl;
    std::cout << "s2: " << s2.getString() << std::endl;

    std::cout << "\n--- Test 2: s2 = s2 (self-assignment) ---" << std::endl;
    s2 = s2;
    std::cout << "s2: " << s2.getString() << std::endl;

    std::cout << "\n--- Test 3: s4 = s3 (assign from empty) ---" << std::endl;
    s4 = s3;
    std::cout << "s4: " << s4.getString() << std::endl;
    std::cout << "s3: " << s3.getString() << std::endl;

    std::cout << "\n--- Test 4: s3 = s5 (assign to empty) ---" << std::endl;
    s3 = s5;
    std::cout << "s3: " << s3.getString() << std::endl;
    std::cout << "s5: " << s5.getString() << std::endl;

    std::cout << "\n--- Test 5: s1 = s3 = s4 (chained assignment) ---" << std::endl;
    s1 = s3 = s4;
    std::cout << "s1: " << s1.getString() << std::endl;
    std::cout << "s3: " << s3.getString() << std::endl;
    std::cout << "s4: " << s4.getString() << std::endl;

    return 0;
}