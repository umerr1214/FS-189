#include <iostream>

// Base class
class Base {
public:
    Base() {
        std::cout << "Base Constructor Called" << std::endl; // Using std::endl
    }

    // Virtual destructor - functionally correct, but uses std::endl
    virtual ~Base() {
        std::cout << "Base Destructor Called" << std::endl; // Using std::endl
    }
};

// Derived class
class Derived : public Base {
public:
    Derived() : Base() { // Explicitly calling base constructor, slightly verbose
        std::cout << "Derived Constructor Called" << std::endl; // Using std::endl
    }

    ~Derived() override { // Using override keyword, good practice
        std::cout << "Derived Destructor Called" << std::endl; // Using std::endl
    }
};

void demonstrateDestruction() { // Encapsulating logic in a function
    std::cout << "--- Starting demonstration function ---" << std::endl;
    Base* dynamicObject = new Derived(); // Using raw new/delete
    std::cout << "Object created. Now deleting..." << std::endl;
    delete dynamicObject;
    std::cout << "--- Demonstration function finished ---" << std::endl;
}

int main() {
    std::cout << "Program starting." << std::endl; // Using std::endl
    demonstrateDestruction();
    std::cout << "Program exiting." << std::endl; // Using std::endl
    return 0;
}