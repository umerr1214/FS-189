#include <iostream>

class Parent {
public:
    Parent() {
        std::cout << "Parent Constructor called.\n";
    }
    ~Parent() {
        std::cout << "Parent Destructor called.\n";
    }
} // Syntax Error: Missing semicolon after class definition

class Child : public Parent {
public:
    Child() {
        std::cout << "Child Constructor called.\n";
    }
    ~Child() {
        std::cout << "Child Destructor called.\n";
    }
};

int main() {
    std::cout << "Creating Child object...\n";
    Child c;
    std::cout << "Child object created.\n";
    std::cout << "Destroying Child object...\n";
    // c goes out of scope here, destructors are called
    std::cout << "Child object destroyed.\n";
    return 0;
}