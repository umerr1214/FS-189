#include <iostream>
#include <cstring> // For strlen, strcpy

// Implement a custom MyString class
class MyString {
private:
    char* data; // Pointer to dynamically allocated C-style string

public:
    // Default constructor & Constructor from const char*
    MyString(const char* str = nullptr) : data(nullptr) {
        if (str) {
            size_t len = std::strlen(str);
            data = new char[len + 1];
            std::strcpy(data, str);
        } else {
            // Handle nullptr by creating an empty string
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Deep Copy Constructor
    MyString(const MyString& other) : data(nullptr) {
        if (other.data) {
            size_t len = std::strlen(other.data);
            data = new char[len + 1];
            std::strcpy(data, other.data);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Destructor
    ~MyString() {
        delete[] data;
        data = nullptr; // Good practice to nullify pointer after deletion
    }

    // Deep Copy Assignment Operator (Robustness Issue: Fails on self-assignment)
    MyString& operator=(const MyString& other) {
        // ISSUE: No self-assignment check (if this == &other)
        // If this == &other, deleting data will delete other.data as well,
        // leading to a dangling pointer for 'other' and then crashing
        // when trying to access other.data in strlen or strcpy.

        delete[] data; // Deletes the original data pointed to by 'this->data'
        data = nullptr; // Set to nullptr to avoid dangling pointer temporarily

        if (other.data) {
            size_t len = std::strlen(other.data); // Accesses dangling 'other.data' if self-assignment
            data = new char[len + 1];
            std::strcpy(data, other.data); // Accesses dangling 'other.data' if self-assignment
        } else {
            data = new char[1];
            data[0] = '\0';
        }
        return *this;
    }

    // Accessor for the C-style string
    const char* c_str() const {
        return data;
    }
};

// Helper function to print MyString details
void printMyString(const char* label, const MyString& s) {
    std::cout << label << ": \"" << s.c_str() << "\" (Address of data: " << static_cast<void*>(const_cast<char*>(s.c_str())) << ")\n";
}

int main() {
    std::cout << "--- MyString Demonstration (Robustness Issue: Self-assignment) ---\n";

    MyString s1("Hello");
    printMyString("s1", s1);

    MyString s2 = s1; // Copy constructor
    printMyString("s2 (copy of s1)", s2);

    MyString s3; // Default constructor
    printMyString("s3 (default)", s3);

    s3 = s1; // Copy assignment
    printMyString("s3 (assigned s1)", s3);

    std::cout << "\n--- Modifying s1 ---\n";
    MyString temp("World");
    s1 = temp; // s1 gets "World"
    printMyString("s1 (assigned temp 'World')", s1);
    printMyString("s2 (should still be 'Hello')", s2); // s2 should be unaffected
    printMyString("s3 (should still be 'Hello')", s3); // s3 should be unaffected

    std::cout << "\n--- CRITICAL: Self-assignment test (Will likely crash or corrupt memory) ---\n";
    // This line demonstrates the robustness issue in operator=
    // When s2 = s2, 'this->data' and 'other.data' point to the same memory.
    // 'delete[] data;' will free the memory, making 'other.data' a dangling pointer.
    // Subsequent access to 'other.data' (e.g., in strlen) will be undefined behavior.
    s2 = s2; // Expected to cause a crash or memory corruption
    printMyString("s2 (after self-assignment)", s2); // Output here might be garbage or crash before reaching

    std::cout << "\n--- Assignment from temporary (if program continues) ---\n";
    s3 = MyString("Temporary"); // Assignment from a temporary object
    printMyString("s3 (assigned temporary)", s3);

    std::cout << "\n--- Objects going out of scope ---\n";
    {
        MyString local_s("Local String");
        printMyString("local_s", local_s);
        MyString local_copy = local_s;
        printMyString("local_copy", local_copy);
    } // local_s and local_copy destruct here
    std::cout << "Local strings went out of scope.\n";

    std::cout << "--- End of Demonstration ---\n";

    return 0;
}