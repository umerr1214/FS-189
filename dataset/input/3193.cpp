#include <iostream>
#include <cstring> // For strcpy, strlen
#include <algorithm> // For std::swap

class MyString {
private:
    char* data_;
    size_t size_; // Does not include null terminator

public:
    // Default constructor
    MyString() : data_(nullptr), size_(0) {
        data_ = new char[1];
        data_[0] = '\0';
    }

    // Constructor from C-style string
    MyString(const char* s) : data_(nullptr), size_(0) {
        if (s) {
            size_ = strlen(s);
            data_ = new char[size_ + 1];
            strcpy(data_, s);
        } else {
            data_ = new char[1];
            data_[0] = '\0';
        }
    }

    // Copy constructor
    MyString(const MyString& other) : data_(nullptr), size_(other.size_) {
        data_ = new char[size_ + 1];
        strcpy(data_, other.data_);
    }

    // Destructor
    ~MyString() {
        delete[] data_;
    }

    // Length accessor
    size_t length() const {
        return size_;
    }

    // C-style string accessor
    const char* c_str() const {
        return data_;
    }

    // Copy assignment operator - Robustness Issue
    // If `new char[other.size_ + 1]` throws std::bad_alloc,
    // the original `data_` has already been deleted, leaving the
    // object in a modified (and potentially empty) state,
    // rather than its original state (violates strong exception guarantee).
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data_; // Deletes original data_
        data_ = nullptr; // Set to nullptr to be safe if new fails

        size_ = other.size_;
        data_ = new char[size_ + 1]; // This allocation might throw std::bad_alloc
        strcpy(data_, other.data_);

        return *this;
    }

    // For testing and output
    friend std::ostream& operator<<(std::ostream& os, const MyString& s) {
        return os << s.data_;
    }
};

int main() {
    std::cout << "--- Testing MyString Copy Assignment Operator (Robustness Issue) ---" << std::endl;

    // Test Case 1: Assigning a shorter string to a longer string
    MyString s1("Hello");
    MyString s2("World!");
    std::cout << "Before s1 = s2: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << std::endl;
    s1 = s2;
    std::cout << "After s1 = s2: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << std::endl;
    if (std::string(s1.c_str()) == "World!") {
        std::cout << "Test 1 Passed." << std::endl;
    } else {
        std::cout << "Test 1 FAILED. Expected 'World!', Got '" << s1 << "'" << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    // Test Case 2: Assigning a longer string to a shorter string
    MyString s3("Long string example");
    MyString s4("Short");
    std::cout << "Before s3 = s4: s3=\"" << s3 << "\", s4=\"" << s4 << "\"" << std::endl;
    s3 = s4;
    std::cout << "After s3 = s4: s3=\"" << s3 << "\", s4=\"" << s4 << "\"" << std::endl;
    if (std::string(s3.c_str()) == "Short") {
        std::cout << "Test 2 Passed." << std::endl;
    } else {
        std::cout << "Test 2 FAILED. Expected 'Short', Got '" << s3 << "'" << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    // Test Case 3: Assigning an empty string
    MyString s5("Initial");
    MyString s6("");
    std::cout << "Before s5 = s6: s5=\"" << s5 << "\", s6=\"" << s6 << "\"" << std::endl;
    s5 = s6;
    std::cout << "After s5 = s6: s5=\"" << s5 << "\", s6=\"" << s6 << "\"" << std::endl;
    if (std::string(s5.c_str()) == "") {
        std::cout << "Test 3 Passed." << std::endl;
    } else {
        std::cout << "Test 3 FAILED. Expected '', Got '" << s5 << "'" << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    // Test Case 4: Self-assignment
    MyString s7("Self");
    std::cout << "Before s7 = s7: s7=\"" << s7 << "\"" << std::endl;
    s7 = s7;
    std::cout << "After s7 = s7: s7=\"" << s7 << "\"" << std::endl;
    if (std::string(s7.c_str()) == "Self") {
        std::cout << "Test 4 Passed." << std::endl;
    } else {
        std::cout << "Test 4 FAILED. Expected 'Self', Got '" << s7 << "'" << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    // Test Case 5: Chained assignment
    MyString s8("A");
    MyString s9("B");
    MyString s10("C");
    std::cout << "Before s8 = s9 = s10: s8=\"" << s8 << "\", s9=\"" << s9 << "\", s10=\"" << s10 << "\"" << std::endl;
    s8 = s9 = s10;
    std::cout << "After s8 = s9 = s10: s8=\"" << s8 << "\", s9=\"" << s9 << "\", s10=\"" << s10 << "\"" << std::endl;
    if (std::string(s8.c_str()) == "C" && std::string(s9.c_str()) == "C") {
        std::cout << "Test 5 Passed." << std::endl;
    } else {
        std::cout << "Test 5 FAILED. Expected s8='C', s9='C'. Got s8='" << s8 << "', s9='" << s9 << "'" << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    // Test Case 6: Assign to default-constructed MyString
    MyString s11;
    MyString s12("New");
    std::cout << "Before s11 = s12: s11=\"" << s11 << "\", s12=\"" << s12 << "\"" << std::endl;
    s11 = s12;
    std::cout << "After s11 = s12: s11=\"" << s11 << "\", s12=\"" << s12 << "\"" << std::endl;
    if (std::string(s11.c_str()) == "New") {
        std::cout << "Test 6 Passed." << std::endl;
    } else {
        std::cout << "Test 6 FAILED. Expected 'New', Got '" << s11 << "'" << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    // Test Case 7: Assignment then copy construction
    MyString s13("Test");
    MyString s14("Testing longer string");
    std::cout << "Before s13 = s14: s13=\"" << s13 << "\", s14=\"" << s14 << "\"" << std::endl;
    s13 = s14;
    std::cout << "After s13 = s14: s13=\"" << s13 << "\", s14=\"" << s14 << "\"" << std::endl;
    MyString s15 = s13; // Uses copy constructor
    std::cout << "After MyString s15 = s13: s15=\"" << s15 << "\"" << std::endl;
    if (std::string(s13.c_str()) == "Testing longer string" && std::string(s15.c_str()) == "Testing longer string") {
        std::cout << "Test 7 Passed." << std::endl;
    } else {
        std::cout << "Test 7 FAILED. Expected 'Testing longer string' for both. Got s13='" << s13 << "', s15='" << s15 << "'" << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    return 0;
}