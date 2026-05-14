#include <iostream>
#include <cstring> // For strlen, strcpy
#include <utility> // For std::swap

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
        data = nullptr;
    }

    // Swap function (often a friend or member) for copy-and-swap idiom
    friend void swap(MyString& first, MyString& second) noexcept {
        using std::swap;
        swap(first.data, second.data);
    }

    // Deep Copy Assignment Operator (using copy-and-swap idiom for robustness and exception safety)
    MyString& operator=(MyString other) noexcept { // Parameter 'other' is passed by value (copy constructor is invoked)
        swap(*this, other); // Swap *this's data with 'other's data
        return *this;       // 'other's destructor will now clean up the old *this data
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
    std::cout << "--- MyString Demonstration (Correct Version) ---\n";

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

    std::cout << "\n--- Self-assignment test ---\n";
    s2 = s2; // Self-assignment (correctly handled by copy-and-swap)
    printMyString("s2 (after self-assignment)", s2);

    std::cout << "\n--- Assignment from temporary ---\n";
    s3 = MyString("Temporary"); // Assignment from a temporary object (efficiently handled by copy-and-swap)
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