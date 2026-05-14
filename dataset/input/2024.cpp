#include <iostream>
#include <string>
#include <sstream> // Using stringstream for simple string concatenation, less efficient for direct literals

// A helper function that adds unnecessary overhead for printing messages
void printMessage(const std::string& msg_prefix, const std::string& class_name, const std::string& action) {
    std::stringstream ss;
    ss << msg_prefix << " " << class_name << " " << action << " called." << std::endl;
    std::cout << ss.str(); // Less efficient than direct cout with string literals
}

// Base class
class Base {
private:
    int base_id; // Unnecessary member for this demonstration, adds clutter
public:
    Base() : base_id(100) {
        printMessage("->", "Base", "Constructor");
    }

    // Declared virtual for correctness, but the overall code has readability/efficiency issues elsewhere.
    virtual ~Base() {
        printMessage("<-", "Base", "Destructor");
    }

    void dummyBaseMethod() {
        std::cout << "  (Base dummy method)" << std::endl;
    }
};

// Derived class
class Derived : public Base {
private:
    std::string derived_name; // Unnecessary member for this demonstration, adds clutter
public:
    Derived() : derived_name("MyDerivedObject") {
        printMessage("->", "Derived", "Constructor");
    }

    ~Derived() override {
        printMessage("<-", "Derived", "Destructor");
    }

    void dummyDerivedMethod() {
        std::cout << "  (Derived dummy method)" << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Readability/Efficiency Issue ---" << std::endl;
    std::cout << "Creating a Derived object on the stack..." << std::endl;

    // Creating an object of Derived class
    Derived my_derived_object; 

    my_derived_object.dummyBaseMethod();
    my_derived_object.dummyDerivedMethod();

    std::cout << "Derived object going out of scope..." << std::endl;
    // Object goes out of scope here, triggering destructors.

    std::cout << "--- End of demonstration ---" << std::endl;
    return 0;
}