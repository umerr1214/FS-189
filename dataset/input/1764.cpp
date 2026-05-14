#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
private:
    char* _data;
    size_t _length;

public:
    // Parameterized Constructor
    StringWrapper(const char* str = nullptr) {
        if (str) {
            _length = strlen(str);
            _data = new char[_length + 1];
            strcpy(_data, str);
        } else {
            _length = 0;
            _data = new char[1];
            _data[0] = '\0';
        }
    }

    // Copy Constructor
    StringWrapper(const StringWrapper& other) {
        _length = other._length;
        _data = new char[_length + 1];
        strcpy(_data, other._data);
    }

    // Copy Assignment Operator - SEMANTIC ERROR: Using 'delete' instead of 'delete[]'
    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this;
        }
        delete _data; // SEMANTIC ERROR: Should be delete[] _data; for array deallocation

        _length = other._length;
        _data = new char[_length + 1];
        strcpy(_data, other._data);
        return *this;
    }

    // Destructor - SEMANTIC ERROR: Using 'delete' instead of 'delete[]'
    ~StringWrapper() {
        delete _data; // SEMANTIC ERROR: Should be delete[] _data; for array deallocation
        _data = nullptr;
    }

    // Getter for string data
    const char* get_string() const {
        return _data;
    }

    // Getter for length
    size_t length() const {
        return _length;
    }
};

void print_wrapper(const StringWrapper& sw, const char* name) {
    std::cout << name << ": \"" << sw.get_string() << "\" (length: " << sw.length() << ")" << std::endl;
}

int main() {
    StringWrapper s1("Hello");
    print_wrapper(s1, "s1");

    StringWrapper s2 = s1;
    print_wrapper(s2, "s2");

    StringWrapper s3;
    print_wrapper(s3, "s3");

    s3 = s1;
    print_wrapper(s3, "s3 after assignment");

    StringWrapper s4("World");
    print_wrapper(s4, "s4");

    s3 = s4;
    print_wrapper(s3, "s3 after re-assignment");

    StringWrapper s5("Longer string test");
    StringWrapper s6("Short");
    s6 = s5;
    print_wrapper(s6, "s6 after longer assignment");

    StringWrapper s7("Very long string that needs reallocation");
    StringWrapper s8("short");
    s8 = s7;
    print_wrapper(s8, "s8 after very long assignment");

    return 0;
}