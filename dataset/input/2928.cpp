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

    // SEMANTIC ERROR: operator= returns StringWrapper by value instead of StringWrapper& (reference).
    // This is syntactically valid but semantically incorrect for assignment operators.
    // It breaks chaining (e.g., a = b = c;) and incurs unnecessary copying.
    StringWrapper operator=(const StringWrapper& other) { 
        if (this == &other) {
            return *this; // Still returns a copy of *this, which is inefficient but correct for self-assignment.
        }

        delete[] data;
        data = nullptr;
        length = 0;

        if (other.data) {
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        
        // A temporary StringWrapper object is created and returned here.
        // This causes issues with chaining and performance.
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
    StringWrapper s1("Hello");
    StringWrapper s2("World");
    StringWrapper s3("C++");
    StringWrapper s4;

    std::cout << "Initial: s1=" << s1 << ", s2=" << s2 << ", s3=" << s3 << ", s4=" << s4 << std::endl;

    s4 = s1;
    std::cout << "After s4 = s1: s4=" << s4 << std::endl;

    s1 = s2;
    std::cout << "After s1 = s2: s1=" << s1 << std::endl;

    s2 = s2;
    std::cout << "After s2 = s2: s2=" << s2 << std::endl;

    s1 = s2 = s3;
    std::cout << "After s1 = s2 = s3: s1=" << s1 << ", s2=" << s2 << ", s3=" << s3 << std::endl;

    StringWrapper empty_str;
    s4 = empty_str;
    std::cout << "After s4 = empty_str: s4=" << s4 << std::endl;

    StringWrapper s5("Temporary");
    s5 = empty_str;
    std::cout << "After s5 = empty_str: s5=" << s5 << std::endl;

    return 0;
}