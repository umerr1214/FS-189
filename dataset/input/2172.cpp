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

    // SEMANTIC ERROR: Missing destructor, leading to memory leaks.
    // The dynamically allocated memory for m_data will not be freed when MyString objects go out of scope.
    // ~MyString() {
    //     delete[] m_data;
    // }

    // Deep Copy Constructor
    MyString(const MyString& other) {
        m_data = new char[strlen(other.m_data) + 1];
        strcpy(m_data, other.m_data);
    }

    // Deep Copy Assignment Operator
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }
        delete[] m_data; // Deallocate old memory (this is correct within the operator)
        m_data = new char[strlen(other.m_data) + 1];
        strcpy(m_data, other.m_data);
        return *this;
    }

    void print() const {
        std::cout << "String: " << m_data << ", Address: " << static_cast<void*>(m_data) << std::endl;
    }
};

int main() {
    MyString s1("Hello World");
    std::cout << "s1 "; s1.print();

    // Demonstrate copy constructor
    MyString s2 = s1; // Calls copy constructor
    std::cout << "s2 (copy of s1) "; s2.print();

    // Modify s1 to show deep copy
    s1.m_data[0] = 'h'; // Direct modification for demonstration, bad practice normally
    std::cout << "s1 (modified) "; s1.print();
    std::cout << "s2 (after s1 modified) "; s2.print();

    MyString s3("Initial");
    std::cout << "s3 "; s3.print();

    // Demonstrate copy assignment operator
    s3 = s1; // Calls copy assignment operator
    std::cout << "s3 (assigned s1) "; s3.print();

    // Modify s1 again to show deep copy
    s1.m_data[0] = 'G';
    std::cout << "s1 (modified again) "; s1.print();
    std::cout << "s3 (after s1 modified again) "; s3.print();

    MyString s4; // Default constructor
    std::cout << "s4 "; s4.print();
    s4 = s2;
    std::cout << "s4 (assigned s2) "; s4.print();

    // All MyString objects created (s1, s2, s3, s4) will leak memory
    // because the destructor is missing. The program will run to completion,
    // but memory allocated on the heap for m_data will not be released.

    return 0;
}