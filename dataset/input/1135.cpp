#include <iostream>
#include <cstring> // For strlen and strcpy

class StringWrapper {
private:
    char* m_data;

public:
    // Constructor: Deep copy the C-style string
    StringWrapper(const char* str) {
        // Robustness Issue: This constructor does not check for nullptr 'str'.
        // Calling strlen(nullptr) or strcpy(..., nullptr) leads to
        // undefined behavior or a crash.
        size_t length = std::strlen(str); // CRASHES if str is nullptr
        m_data = new char[length + 1];
        std::strcpy(m_data, str); // CRASHES if str is nullptr
        std::cout << "StringWrapper created for: \"" << m_data << "\"" << std::endl;
    }

    // Destructor: Release dynamically allocated memory
    ~StringWrapper() {
        if (m_data != nullptr) {
            std::cout << "StringWrapper for \"" << m_data << "\" destroyed." << std::endl;
            delete[] m_data;
            m_data = nullptr; // Prevent double deletion, though not strictly necessary in a destructor
        } else {
            std::cout << "StringWrapper for (nullptr) destroyed." << std::endl;
        }
    }

    // Method to get the string (for demonstration)
    const char* get_string() const {
        return m_data;
    }
};

int main() {
    std::cout << "--- Demonstrating StringWrapper with valid input ---" << std::endl;
    StringWrapper s1("Hello C++");
    std::cout << "s1 content: " << s1.get_string() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Demonstrating StringWrapper with nullptr input (expected crash) ---" << std::endl;
    // This will cause a crash or undefined behavior due to strlen(nullptr)
    StringWrapper s2(nullptr);
    std::cout << "s2 content: " << s2.get_string() << std::endl;
    std::cout << std::endl;

    std::cout << "Program finished." << std::endl; // This line might not be reached
    return 0;
}