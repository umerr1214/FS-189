#include <iostream>
#include <cstring> // For strlen, strcpy

class MyString {
public:
    char* m_data;

    MyString(const char* str = nullptr) {
        if (str == nullptr) {
            m_data = new char[1];
            m_data[0] = '\0';
        } else {
            m_data = new char[strlen(str) + 1];
            strcpy(m_data, str);
        }
    }

    ~MyString() {
        delete[] m_data;
    }

    // Deep Copy Constructor
    MyString(const MyString& other) {
        // LOGICAL ERROR: Not allocating enough space for null terminator.
        // This will lead to a buffer overflow when strcpy attempts to write the null terminator.
        m_data = new char[strlen(other.m_data)]; // Should be strlen(other.m_data) + 1
        strcpy(m_data, other.m_data);
    }

    // Deep Copy Assignment Operator
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }
        delete[] m_data; // Deallocate old memory
        // LOGICAL ERROR: Not allocating enough space for null terminator.
        // This will lead to a buffer overflow when strcpy attempts to write the null terminator.
        m_data = new char[strlen(other.m_data)]; // Should be strlen(other.m_data) + 1
        strcpy(m_data, other.m_data);
        return *this;
    }

    void print() const {
        std::cout << "String: " << m_data << ", Address: " << static_cast<void*>(m_data) << std::endl;
    }
};

int main() {
    MyString s1("Hello"); // String length 5. Allocates 5 bytes. strcpy writes 6 bytes ('H','e','l','l','o','\0'). Buffer overflow.
    std::cout << "s1 "; s1.print();

    MyString s2 = s1; // Calls copy constructor, same error
    std::cout << "s2 (copy of s1) "; s2.print();

    MyString s3("World"); // String length 5. Allocates 5 bytes. strcpy writes 6 bytes. Buffer overflow.
    std::cout << "s3 "; s3.print();

    s3 = s1; // Calls copy assignment operator, same error
    std::cout << "s3 (assigned s1) "; s3.print();

    // Due to the buffer overflows, subsequent operations or destructor calls might crash or show corrupted data.
    // For example, changing s1 could corrupt memory adjacent to s1's data.
    // s1.m_data[0] = 'h'; // This might cause a crash or further corruption depending on memory layout

    return 0;
}