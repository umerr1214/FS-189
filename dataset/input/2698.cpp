#include <iostream>
#include <cstring> // For strlen, strcpy

class MyString {
private:
    char* data;
    int length;

publc: // Syntax error: misspelled 'public'
    // Constructor
    MyString(const char* s = "") {
        if (s == nullptr) {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            length = strlen(s);
            data = new char[length + 1];
            strcpy(data, s);
        }
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy Constructor (Deep Copy)
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Accessor for testing
    const char* c_str() const {
        return data;
    }

    int getLength() const {
        return length;
    }
};

int main() {
    // This code will not compile due to the syntax error in the MyString class definition.
    // MyString s1("Hello Syntax");
    // MyString s2 = s1;

    // std::cout << "s1: " << s1.c_str() << ", Length: " << s1.getLength() << std::endl;
    // std::cout << "s2: " << s2.c_str() << ", Length: " << s2.getLength() << std::endl;

    return 0;
}