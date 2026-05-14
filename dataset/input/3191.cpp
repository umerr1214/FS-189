#include <iostream>
#include <cstring> // For strlen, strcpy

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

    // Constructor from C-string
    MyString(const char* str) : length(0) {
        if (str) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Copy constructor
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Accessor
    const char* c_str() const {
        return data;
    }

    size_t getLength() const {
        return length;
    }

    // Logical error: Forgetting to delete[] data; before reallocation, causing a memory leak.
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }

        // PROBLEM: Old 'data' is not deleted, leading to a memory leak.
        // The previous memory block pointed to by 'data' is lost and cannot be freed.
        // delete[] data; // This line is missing!

        length = other.length;
        data = new char[length + 1]; // Allocates new memory
        std::strcpy(data, other.data);

        return *this;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3; // s3 initially holds an empty string, memory for "" is allocated.

    std::cout << "s1: " << s1.c_str() << ", Length: " << s1.getLength() << std::endl;
    std::cout << "s2: " << s2.c_str() << ", Length: " << s2.getLength() << std::endl;

    s3 = s1; // Assignment. The memory for s3's initial "" is leaked.

    std::cout << "s3 after s3 = s1: " << s3.c_str() << ", Length: " << s3.getLength() << std::endl;

    MyString s4("Test string that is quite long"); // s4 holds a long string.
    MyString s5("Short");
    s4 = s5; // Assignment. The memory for s4's initial long string is leaked.

    std::cout << "s4 after s4 = s5: " << s4.c_str() << ", Length: " << s4.getLength() << std::endl;

    MyString s6("Another test");
    s6 = s6; // Self-assignment. No leak here as old data is not touched, and no new allocation.
    std::cout << "s6 after self-assignment: " << s6.c_str() << ", Length: " << s6.getLength() << std::endl;

    // The program will run and produce correct output, but with memory leaks
    // which can be detected by memory profiling tools like Valgrind.

    return 0;
}