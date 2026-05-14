#include <iostream>
#include <cstring> // For strlen, strcpy
#include <algorithm> // For std::swap

class StringWrapper {
private:
    char* data;
    size_t length;

public:
    StringWrapper(const char* str = nullptr) : data(nullptr), length(0) {
        if (str) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        }
    }

    ~StringWrapper() {
        delete[] data;
    }

    StringWrapper(const StringWrapper& other) : data(nullptr), length(0) {
        if (other.data) {
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
    }

    StringWrapper(StringWrapper&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    const char* get() const { return data ? data : ""; }
    size_t size() const { return length; }

    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this;
        }

        // LOGICAL ERROR: Memory leak. The old 'data' is not deallocated before assigning new memory.
        // The line 'delete[] data;' is missing here.

        // Allocate new memory and copy data from 'other'
        char* new_data = nullptr;
        size_t new_length = 0;
        if (other.data) {
            new_length = other.length;
            new_data = new char[new_length + 1];
            std::strcpy(new_data, other.data);
        }
        
        // The old 'data' pointed to by 'this->data' is now leaked.
        data = new_data;
        length = new_length;

        return *this;
    }

    StringWrapper& operator=(StringWrapper&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }
};

std::ostream& operator<<(std::ostream& os, const StringWrapper& sw) {
    return os << "\"" << sw.get() << "\" (len: " << sw.size() << ")";
}

int main() {
    StringWrapper s1("Hello"); // s1 allocates "Hello"
    StringWrapper s2("World"); // s2 allocates "World"
    StringWrapper s3("C++");   // s3 allocates "C++"
    StringWrapper s4;          // s4 allocates nothing (nullptr)

    std::cout << "Initial: s1=" << s1 << ", s2=" << s2 << ", s3=" << s3 << ", s4=" << s4 << std::endl;

    s4 = s1; // s4 takes "Hello". No leak here if s4.data was nullptr.
    std::cout << "After s4 = s1: s4=" << s4 << std::endl;

    s1 = s2; // s1 had "Hello", now takes "World". "Hello" memory is leaked here.
    std::cout << "After s1 = s2: s1=" << s1 << std::endl;

    s2 = s2; // Self-assignment, no leak.
    std::cout << "After s2 = s2: s2=" << s2 << std::endl;

    s1 = s2 = s3; // s2 had "World", now takes "C++". "World" memory is leaked.
                  // s1 had "World", now takes "C++". "World" memory is leaked.
    std::cout << "After s1 = s2 = s3: s1=" << s1 << ", s2=" << s2 << ", s3=" << s3 << std::endl;

    StringWrapper empty_str; // empty_str allocates nothing (nullptr)
    s4 = empty_str; // s4 had "Hello", now takes "". "Hello" memory is leaked.
    std::cout << "After s4 = empty_str: s4=" << s4 << std::endl;

    StringWrapper s5("Temporary"); // s5 allocates "Temporary"
    s5 = empty_str; // s5 had "Temporary", now takes "". "Temporary" memory is leaked.
    std::cout << "After s5 = empty_str: s5=" << s5 << std::endl;

    return 0;
}