#include <iostream>
#include <cstring> // For strlen, strcpy (though we'll avoid in inefficient parts)

// Implement a custom MyString class
class MyString {
private:
    char* data; // Pointer to dynamically allocated C-style string

public:
    // Default constructor & Constructor from const char*
    MyString(const char* str = nullptr) : data(nullptr) {
        if (str) {
            size_t len = std::strlen(str); // Efficient strlen here
            data = new char[len + 1];
            std::strcpy(data, str); // Efficient strcpy here
        } else {
            // Handle nullptr by creating an empty string
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Deep Copy Constructor (Readability/Efficiency Issue: manual loop for copy)
    MyString(const MyString& other) : data(nullptr) {
        if (other.data) {
            size_t len = 0;
            // Inefficient: Manual strlen loop instead of std::strlen
            while (other.data[len] != '\0') {
                len++;
            }
            data = new char[len + 1];
            // Inefficient: Manual character copy loop instead of std::strcpy
            for (size_t i = 0; i <= len; ++i) {
                data[i] = other.data[i];
            }
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

    // Deep Copy Assignment Operator (Readability/Efficiency Issue: always reallocates, manual loop)
    MyString& operator=(const MyString& other) {
        if (this == &other) { // Self-assignment check is present
            return *this;
        }

        // Inefficient: Always deallocates and reallocates, even if current buffer is sufficient.
        // This is less efficient than checking current capacity and potentially reusing.
        delete[] data;
        data = nullptr; // Defensive nullification

        if (other.data) {
            size_t len = 0;
            // Inefficient: Manual strlen loop instead of std::strlen
            while (other.data[len] != '\0') {
                len++;
            }
            data = new char[len + 1];
            // Inefficient: Manual character copy loop instead of std::strcpy
            for (size_t i = 0; i <= len; ++i) {
                data[i] = other.data[i];
            }
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
    std::cout << "--- MyString Demonstration (Readability/Efficiency Issue) ---\n";

    MyString s1("Hello");
    printMyString("s1", s1);

    MyString s2 = s1; // Copy constructor (uses inefficient manual loop)
    printMyString("s2 (copy of s1)", s2);

    MyString s3; // Default constructor
    printMyString("s3 (default)", s3);

    s3 = s1; // Copy assignment (uses inefficient manual loop and reallocates)
    printMyString("s3 (assigned s1)", s3);

    std::cout << "\n--- Modifying s1 ---\n";
    MyString temp("World");
    s1 = temp; // s1 gets "World" (uses inefficient manual loop and reallocates)
    printMyString("s1 (assigned temp 'World')", s1);
    printMyString("s2 (should still be 'Hello')", s2); // s2 should be unaffected
    printMyString("s3 (should still be 'Hello')", s3); // s3 should be unaffected

    std::cout << "\n--- Self-assignment test ---\n";
    s2 = s2; // Self-assignment (handled, but still inefficient due to always reallocating if not for early exit)
    printMyString("s2 (after self-assignment)", s2);

    std::cout << "\n--- Assignment from temporary ---\n";
    s3 = MyString("Temporary"); // Assignment from a temporary object (uses inefficient manual loop and reallocates)
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