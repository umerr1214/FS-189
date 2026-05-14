#include <iostream>
#include <cstring> // For strlen, strcpy
#include <algorithm> // For std::swap

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

    // Copy constructor (essential for copy-and-swap idiom)
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

    // Swap function (essential for copy-and-swap idiom)
    void swap(StringWrapper& other) noexcept {
        using std::swap;
        swap(m_str, other.m_str);
    }

    // Correct Version: Copy assignment operator using copy-and-swap idiom
    // 'other' is passed by value, so a copy is made (using copy constructor).
    // This copy handles allocation and deep copying.
    StringWrapper& operator=(StringWrapper other) noexcept {
        // Swap *this's data with the temporary 'other'.
        // The old data of *this is now in 'other', which will be destroyed
        // when 'other' goes out of scope, handling deallocation automatically.
        swap(other);
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