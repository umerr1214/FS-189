#include <iostream>
#include <cstring> // Included, but its functions are deliberately avoided for inefficiency

class MyString {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    MyString() : data(nullptr), length(0) {
        data = new char[1];
        data[0] = '\0';
    }

    // Constructor from const char* - EFFICIENCY ISSUE
    MyString(const char* s) {
        if (s == nullptr) { // Basic null check to prevent crash, but operations remain inefficient
            length = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            // Inefficient: Manually calculate length instead of std::strlen
            size_t temp_len = 0;
            while (s[temp_len] != '\0') {
                temp_len++;
            }
            length = temp_len;
            data = new char[length + 1];

            // Inefficient: Manually copy character by character instead of std::strcpy
            for (size_t i = 0; i <= length; ++i) {
                data[i] = s[i];
            }
        }
    }

    // Copy Constructor - EFFICIENCY ISSUE
    MyString(const MyString& other) {
        // Inefficient: Recalculate length from 'other.data' even though 'other.length' is available
        size_t temp_len = 0;
        if (other.data != nullptr) { // Defensive check
            while (other.data[temp_len] != '\0') {
                temp_len++;
            }
        }
        length = temp_len; // Assign calculated length
        data = new char[length + 1];

        // Inefficient: Manually copy character by character instead of std::strcpy
        for (size_t i = 0; i <= length; ++i) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy Assignment Operator - EFFICIENCY ISSUE
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data; // Free old memory

        // Inefficient: Recalculate length from 'other.data'
        size_t temp_len = 0;
        if (other.data != nullptr) {
            while (other.data[temp_len] != '\0') {
                temp_len++;
            }
        }
        length = temp_len; // Assign calculated length
        data = new char[length + 1];

        // Inefficient: Manually copy character by character
        for (size_t i = 0; i <= length; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Getter for string content
    const char* c_str() const {
        return data;
    }

    // Getter for string length
    size_t size() const {
        return length;
    }
};

int main() {
    std::cout << "Testing MyString with readability/efficiency issues.\n";

    MyString s1("Efficiency Test String 1");
    std::cout << "s1: " << s1.c_str() << " (length: " << s1.size() << ")\n";

    MyString s2 = s1; // Copy constructor
    std::cout << "s2 (copy of s1): " << s2.c_str() << " (length: " << s2.size() << ")\n";

    MyString s3("Another String for Assignment");
    s3 = s1; // Copy assignment
    std::cout << "s3 (assigned s1): " << s3.c_str() << " (length: " << s3.size() << ")\n";

    MyString s4(""); // Empty string
    std::cout << "s4 (empty): " << s4.c_str() << " (length: " << s4.size() << ")\n";

    MyString s5(nullptr); // Null string (handled, but still inefficient)
    std::cout << "s5 (nullptr input): " << s5.c_str() << " (length: " << s5.size() << ")\n";

    // Test long string for efficiency impact
    std::string long_str_val(1000, 'A');
    MyString s_long(long_str_val.c_str());
    std::cout << "s_long (1000 'A's): " << s_long.c_str()[0] << s_long.c_str()[1] << s_long.c_str()[2] << "..." << s_long.c_str()[997] << s_long.c_str()[998] << s_long.c_str()[999] << " (length: " << s_long.size() << ")\n";

    MyString s_long_copy = s_long;
    std::cout << "s_long_copy (copy of s_long): " << s_long_copy.c_str()[0] << s_long_copy.c_str()[1] << s_long_copy.c_str()[2] << "..." << s_long_copy.c_str()[997] << s_long_copy.c_str()[998] << s_long_copy.c_str()[999] << " (length: " << s_long_copy.size() << ")\n";

    return 0;
}