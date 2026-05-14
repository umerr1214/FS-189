#include <iostream>
#include <cstring> // For std::strlen and std::strcpy

class StringWrapper {
private:
    char* m_data;

public:
    // Constructor: Takes a const char* and performs a deep copy
    StringWrapper(const char* str) {
        if (str == nullptr) {
            // Handle nullptr input gracefully by creating an empty string
            m_data = new char[1];
            m_data[0] = '\0';
            std::cout << "StringWrapper created for: \"\" (from nullptr input)" << std::endl;
        } else {
            // Perform deep copy using standard library functions for efficiency and correctness
            size_t length = std::strlen(str);
            m_data = new char[length + 1]; // +1 for the null terminator
            std::strcpy(m_data, str);
            std::cout << "StringWrapper created for: \"" << m_data << "\"" << std::endl;
        }
    }

    // Destructor: Releases the dynamically allocated memory
    ~StringWrapper() {
        // Demonstrate memory leak prevention by explicitly deleting the heap memory
        if (m_data != nullptr) {
            std::cout << "StringWrapper for \"" << m_data << "\" destroyed. Memory released." << std::endl;
            delete[] m_data;
            m_data = nullptr; // Good practice to nullify pointer after deletion
        } else {
            std::cout << "StringWrapper (empty/nullptr) destroyed. Memory released (if any)." << std::endl;
        }
    }

    // Method to get the string content
    const char* get_string() const {
        return m_data;
    }
};

int main() {
    std::cout << "--- Demonstrating StringWrapper functionality ---" << std::endl;

    // Test case 1: Valid string
    StringWrapper s1("Hello World!");
    std::cout << "s1 content: " << s1.get_string() << std::endl;
    std::cout << std::endl;

    // Test case 2: Empty string
    StringWrapper s2("");
    std::cout << "s2 content: \"" << s2.get_string() << "\"" << std::endl;
    std::cout << std::endl;

    // Test case 3: nullptr input
    StringWrapper s3(nullptr);
    std::cout << "s3 content: \"" << s3.get_string() << "\"" << std::endl;
    std::cout << std::endl;

    // Objects go out of scope here, triggering destructors and demonstrating memory release.
    std::cout << "All StringWrapper objects created. Now exiting main, destructors will be called." << std::endl;
    return 0;
}