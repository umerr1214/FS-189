#include <iostream> // For std::cout and std::endl

// Base class
class Parent {
public:
    Parent() {
        std::cout << "Parent Constructor Called" << std::endl;
    }

    // A virtual destructor is crucial for base classes in polymorphic hierarchies
    // to ensure proper cleanup of derived objects when deleted via a base pointer.
    virtual ~Parent() {
        std::cout << "Parent Destructor Called" << std::endl;
    }
};

// Derived class
class Child : public Parent {
public:
    Child() {
        std::cout << "Child Constructor Called" << std::endl;
    }

    ~Child() override { // Using 'override' keyword for clarity (C++11 and later)
        std::cout << "Child Destructor Called" << std::endl;
    }
};

int main() {
    // Demonstrate creation and destruction of a Child object
    // Stack allocation is simple, efficient, and appropriate for this demonstration.
    std::cout << "--- Creating Child object ---" << std::endl;
    Child myChild; // Child object created on the stack
    std::cout << "--- Child object created ---" << std::endl;

    // The object will be automatically destroyed when it goes out of scope (at the end of main),
    // demonstrating the destructor call order.
    std::cout << "--- Child object going out of scope ---" << std::endl;

    return 0;
}