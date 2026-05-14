#include <iostream>

class Parent {
public:
    Parent() {
        std::cout << "Parent Constructor called.\n";
    }
    ~Parent() {
        std::cout << "Parent Destructor called.\n";
    }
};

class Child : public Parent {
public:
    Child() {
        std::cout << "Child Constructor called.\n";
    }
    ~Child() {
        // Logical Error: The Child destructor does not print its own destruction message.
        // It should include: std::cout << "Child Destructor called.\n";
    }
};

int main() {
    std::cout << "Creating Child object...\n";
    Child c;
    std::cout << "Child object created.\n";
    std::cout << "Destroying Child object...\n";
    // c goes out of scope here, destructors are called (Child then Parent)
    std::cout << "Child object destroyed.\n";
    return 0;
}