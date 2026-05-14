#include <iostream>
#include <cstring> // For strlen, strcpy
#include <vector>  // To create multiple objects and demonstrate leaks
#include <string>  // For std::to_string

class StringWrapper {
public:
    char* data;
    size_t length;

    // Default constructor
    StringWrapper(const char* str = "") {
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        } else {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Copy constructor (performs deep copy - CORRECT)
    StringWrapper(const StringWrapper& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // !!! SEMANTIC ERROR: Missing destructor !!!
    // ~StringWrapper() {
    //     delete[] data;
    // }

    // Helper to print string
    void print() const {
        std::cout << data << std::endl;
    }

    const char* get() const {
        return data;
    }
};

void createAndDestroyWrappers() {
    std::cout << "\n--- Function Scope Test (Memory Leak) ---" << std::endl;
    StringWrapper s_func1("Temporary String 1");
    StringWrapper s_func2 = s_func1; // Deep copy
    std::cout << "Inside function: s_func1: "; s_func1.print();
    std::cout << "Inside function: s_func2: "; s_func2.print();
    // s_func1 and s_func2 go out of scope here.
    // Their `data` memory is NOT freed due to missing destructor, leading to a leak.
}

int main() {
    std::cout << "--- Main Scope Test ---" << std::endl;
    StringWrapper s1("Hello");
    std::cout << "s1: ";
    s1.print();

    StringWrapper s2 = s1; // Calls copy constructor (deep copy)
    std::cout << "s2 (copy of s1): ";
    s2.print();

    StringWrapper s3("World");
    std::cout << "s3: ";
    s3.print();

    // Demonstrate independent memory allocation
    std::cout << "s1 address: " << (void*)s1.get() << std::endl;
    std::cout << "s2 address: " << (void*)s2.get() << std::endl;
    std::cout << "s3 address: " << (void*)s3.get() << std::endl;

    createAndDestroyWrappers();

    // Create many objects to highlight the leak
    std::cout << "\n--- Creating many objects (more leaks) ---" << std::endl;
    std::vector<StringWrapper> wrappers;
    for (int i = 0; i < 5; ++i) {
        std::string temp_str = "Vector String " + std::to_string(i);
        wrappers.emplace_back(temp_str.c_str());
    }
    std::cout << "Vector objects created." << std::endl;
    // When 'wrappers' vector goes out of scope, its elements are destructed.
    // But since StringWrapper has no destructor, their 'data' memory leaks.

    std::cout << "\nProgram finished." << std::endl;

    return 0;
}