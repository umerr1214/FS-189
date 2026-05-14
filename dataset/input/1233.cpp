#include <iostream>
#include <cstring> // For strlen, strcpy_s (on MSVC) or strncpy (for cross-platform safety)
#include <algorithm> // For std::swap
#include <stdexcept> // For std::bad_alloc

// A simple helper for strcpy_s on platforms where it's not standard
#ifdef _MSC_VER
#define STRCPY_S(dest, dest_size, src) strcpy_s(dest, dest_size, src)
#else
// Using strncpy for safety, ensuring null termination
inline void safe_strcpy(char* dest, size_t dest_size, const char* src) {
    if (dest == nullptr || dest_size == 0) return;
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0';
}
#define STRCPY_S(dest, dest_size, src) safe_strcpy(dest, dest_size, src)
#endif

class StringWrapper {
private:
    char* data;

public:
    // Default and C-string constructor
    StringWrapper(const char* str = nullptr) : data(nullptr) {
        if (str) {
            size_t len = std::strlen(str);
            data = new char[len + 1];
            STRCPY_S(data, len + 1, str);
        } else {
            // Represent an empty string as a null-terminated empty buffer
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Deep Copy Constructor
    StringWrapper(const StringWrapper& other) : data(nullptr) {
        if (other.data) {
            size_t len = std::strlen(other.data);
            data = new char[len + 1];
            STRCPY_S(data, len + 1, other.data);
        } else {
            // This path should ideally not be taken if `other.data` is always validly initialized.
            // But as a fallback, ensure `data` is a valid empty string.
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
        data = nullptr; // Good practice to nullify pointer after deletion
    }

    // Copy Assignment Operator (using copy-and-swap idiom for strong exception safety)
    StringWrapper& operator=(StringWrapper other) { // 'other' is passed by value (copy constructor is called)
        std::swap(data, other.data); // Swap the internal data pointers
        return *this; // 'other's destructor will clean up the old 'this->data'
    }

    // Getter for the C-style string
    const char* get() const {
        return data;
    }

    // Function to print the string
    void print(const char* prefix = "") const {
        std::cout << prefix << (data ? data : "(null)") << std::endl;
    }
};

int main() {
    std::cout << "--- Testing Correct Version ---" << std::endl;

    // Test Case 1: Default constructor and C-string constructor
    StringWrapper s_empty;
    s_empty.print("s_empty: ");

    StringWrapper s_hello("Hello");
    s_hello.print("s_hello: ");

    // Test Case 2: Deep Copy Constructor
    StringWrapper s_copy = s_hello; // Calls copy constructor
    s_copy.print("s_copy (from s_hello): ");

    // Modify original to ensure copy is deep
    // (Cannot directly modify s_hello here without a setter, but memory addresses would differ)
    // For demonstration, let's create another string and copy it.
    StringWrapper s_world("World!");
    StringWrapper s_copy_world = s_world;
    s_copy_world.print("s_copy_world (from s_world): ");

    // Test Case 3: Deep Copy Assignment Operator
    StringWrapper s_assigned("Original Content");
    s_assigned.print("s_assigned (before assignment): ");

    s_assigned = s_hello; // Calls copy assignment operator
    s_assigned.print("s_assigned (after s_hello assignment): ");

    StringWrapper s_another("Another one");
    s_another.print("s_another (initial): ");
    s_another = s_world; // Calls copy assignment operator
    s_another.print("s_another (after s_world assignment): ");

    // Test Case 4: Self-assignment (should work correctly due to copy-and-swap)
    std::cout << "Self assigning s_hello = s_hello..." << std::endl;
    s_hello = s_hello;
    s_hello.print("s_hello (after self-assignment): ");

    // Test Case 5: Assignment to empty string
    s_assigned = s_empty;
    s_assigned.print("s_assigned (after s_empty assignment): ");

    std::cout << "--- End Test ---" << std::endl;

    return 0;
}