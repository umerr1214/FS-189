#include <iostream>
#include <cstring> // For size_t, but strlen/strcpy are implemented manually

class StringWrapper {
private:
    char* m_data;

    // Helper to manually calculate string length (less efficient/readable than std::strlen)
    size_t manual_strlen(const char* s) {
        if (s == nullptr) return 0;
        size_t len = 0;
        while (s[len] != '\0') {
            len++;
        }
        return len;
    }

    // Helper to manually copy string (less efficient/readable than std::strcpy)
    void manual_strcpy(char* dest, const char* src) {
        if (dest == nullptr || src == nullptr) return;
        size_t i = 0;
        while ((dest[i] = src[i]) != '\0') {
            i++;
        }
    }

public:
    // Constructor: Deep copy the C-style string
    StringWrapper(const char* str) {
        if (str == nullptr) {
            m_data = new char[1];
            m_data[0] = '\0'; // Represent nullptr as an empty string
            std::cout << "StringWrapper created for: \"\" (from nullptr)" << std::endl;
        } else {
            // Readability/Efficiency Issue: Using manual string operations instead of std::strlen/std::strcpy
            size_t length = manual_strlen(str);
            m_data = new char[length + 1];
            manual_strcpy(m_data, str);
            std::cout << "StringWrapper created for: \"" << m_data << "\"" << std::endl;
        }
    }

    // Destructor: Release dynamically allocated memory
    ~StringWrapper() {
        if (m_data != nullptr) {
            std::cout << "StringWrapper for \"" << m_data << "\" destroyed." << std::endl;
            delete[] m_data;
            m_data = nullptr;
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
    std::cout << "--- Demonstrating StringWrapper with various inputs ---" << std::endl;

    StringWrapper s1("Efficient code is good code!");
    std::cout << "s1 content: " << s1.get_string() << std::endl;
    std::cout << std::endl;

    StringWrapper s2("");
    std::cout << "s2 content: \"" << s2.get_string() << "\"" << std::endl;
    std::cout << std::endl;

    StringWrapper s3(nullptr);
    std::cout << "s3 content: \"" << s3.get_string() << "\"" << std::endl;
    std::cout << std::endl;

    std::cout << "Program finished." << std::endl;
    return 0;
}