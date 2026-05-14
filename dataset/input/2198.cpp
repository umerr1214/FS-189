#include <iostream> // For std::cout and std::endl
#include <cstdio>   // For printf - demonstrating inconsistent I/O

// Base class
class Parent {
public:
    Parent() {
        std::cout << "Parent Constructor Called" << std::endl;
    }

    // Make destructor virtual for correctness, but the overall style is poor
    virtual ~Parent() {
        printf("Parent Destructor Called\n"); // Inconsistent I/O method
    }
};

// Derived class
class Child : public Parent {
public:
    Child() {
        std::cout << "Child Constructor Called" << std::endl;
    }

    ~Child() {
        printf("Child Destructor Called\n"); // Inconsistent I/O method
    }
};

int main() {
    // Readability/Efficiency Issue: Unnecessary dynamic allocation
    // For a simple demonstration like this, stack allocation is sufficient,
    // more efficient, and less verbose. Dynamic allocation introduces
    // overhead and the need for manual memory management (new/delete).
    Parent* myChildPtr = new Child(); // Dynamically allocate a Child object
    
    // Demonstrate the order of destruction
    delete myChildPtr; // Manually deallocate the object

    return 0;
}