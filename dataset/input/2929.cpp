#include <cstring> // For strlen, strcpy
#include <iostream> // For output
#include <algorithm> // For std::swap (though not directly used in this operator= version)
#include <vector>
#include <string>

class StringWrapper {
private:
    char* data;
    size_t length;

public:
    // Default Constructor
    StringWrapper(const char* str = "") : data(nullptr), length(0) {
        if (str) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        } else {
            data = new char[1]; // Ensure data is always a valid pointer
            data[0] = '\0';
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Copy Constructor
    StringWrapper(const StringWrapper& other) : data(nullptr), length(0) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Move Constructor (for completeness, not directly relevant to the question)
    StringWrapper(StringWrapper&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    // Accessor
    const char* get() const {
        return data;
    }

    size_t size() const {
        return length;
    }

    // Friend swap function (for completeness, not directly used in this operator= version)
    friend void swap(StringWrapper& first, StringWrapper& second) noexcept {
        using std::swap;
        swap(first.data, second.data);
        swap(first.length, second.length);
    }

    // Robustness Issue: Missing self-assignment protection.
    // Self-assignment (e.g., `s = s;`) will lead to a use-after-free error,
    // as `data` is deleted before its content is copied from `other.data`
    // which is the same memory location.
    StringWrapper& operator=(const StringWrapper& other) {
        // No self-assignment check: if (this == &other) return *this;
        
        delete[] data; // Problem: If *this == &other, this frees the source's data.
                       // Accessing other.data afterwards is undefined behavior.

        length = other.length;
        // Potential issue: If new char[] throws, 'data' is a dangling pointer,
        // leaving *this in an invalid state (not exception-safe).
        data = new char[length + 1];
        
        std::strcpy(data, other.data); // Reading from freed memory if self-assignment.
        return *this;
    }
};

void run_test(const std::string& test_name, const StringWrapper& expected, const StringWrapper& actual) {
    std::cout << "Test: " << test_name << std::endl;
    std::cout << "  Expected: \"" << expected.get() << "\" (len " << expected.size() << ")" << std::endl;
    std::cout << "  Actual:   \"" << actual.get() << "\" (len " << actual.size() << ")" << std::endl;
    if (std::strcmp(expected.get(), actual.get()) == 0 && expected.size() == actual.size()) {
        std::cout << "  Status: PASSED" << std::endl;
    } else {
        std::cout << "  Status: FAILED" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Test Case 1: Basic assignment
    StringWrapper s1("Hello");
    StringWrapper s2("World");
    s1 = s2; // s1 should become "World"
    run_test("Basic assignment (s1 = s2)", StringWrapper("World"), s1);

    // Test Case 2: Self-assignment (THIS WILL LIKELY CRASH OR LEAD TO UB)
    StringWrapper s3("Self");
    s3 = s3; // s3 should remain "Self"
    run_test("Self-assignment (s3 = s3)", StringWrapper("Self"), s3);

    // Test Case 3: Chained assignment
    StringWrapper s4("One");
    StringWrapper s5("Two");
    StringWrapper s6("Three");
    s4 = s5 = s6; // s4 and s5 should become "Three"
    run_test("Chained assignment (s4 = s5 = s6) - s4", StringWrapper("Three"), s4);
    run_test("Chained assignment (s4 = s5 = s6) - s5", StringWrapper("Three"), s5);

    // Test Case 4: Assignment to an empty string
    StringWrapper s7; // Empty
    StringWrapper s8("Non-empty");
    s7 = s8; // s7 should become "Non-empty"
    run_test("Assignment to empty (s7 = s8)", StringWrapper("Non-empty"), s7);

    // Test Case 5: Assignment from an empty string
    StringWrapper s9("Original");
    StringWrapper s10; // Empty
    s9 = s10; // s9 should become empty
    run_test("Assignment from empty (s9 = s10)", StringWrapper(""), s9);

    // Test Case 6: Assignment multiple times
    StringWrapper s11("First");
    StringWrapper s12("Second");
    StringWrapper s13("Third");
    s11 = s12;
    s11 = s13; // s11 should become "Third"
    run_test("Multiple assignments (s11 = s12; s11 = s13)", StringWrapper("Third"), s11);

    return 0;
}