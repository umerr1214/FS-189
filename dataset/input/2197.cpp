#include <iostream>

// Base class
class Parent {
public:
    Parent() {
        std::cout << "Parent Constructor Called" << std::endl;
    }

    // Robustness Issue: Non-virtual destructor in a base class
    // This can lead to undefined behavior or resource leaks if a derived object
    // is deleted through a base class pointer.
    ~Parent() {
        std::cout << "Parent Destructor Called" << std::endl;
    }
};

// Derived class
class Child : public Parent {
public:
    Child() {
        std::cout << "Child Constructor Called" << std::endl;
    }

    ~Child() {
        std::cout << "Child Destructor Called" << std::endl;
    }
};

int main() {
    // Demonstrate creation and destruction of a Child object
    // Using dynamic allocation to highlight the non-virtual destructor issue
    // if Child had unique resources and was deleted via Parent*
    Parent* obj = new Child(); // Parent pointer pointing to a Child object
    delete obj; // Calls Parent's destructor, but not Child's if Parent's destructor is not virtual.
                // For this specific simple example, the compiler might optimize or the specific
                // behavior might vary, but the design flaw remains.
                // On most systems, for a simple object like this, it might still call Child's destructor
                // due to compiler optimizations or specific language rules for trivial destructors.
                // However, the *intent* of the robustness issue is the design flaw.

    return 0;
}