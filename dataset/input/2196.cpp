#include <iostream>

class Parent {
public:
    Parent() {
        std::cout << "Parent Constructor called.\n";
    }
    // Semantic Error: Destructor is not virtual. This can lead to incorrect destruction
    // if a Child object is deleted through a Parent pointer.
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
        std::cout << "Child Destructor called.\n";
    }
};

int main() {
    std::cout << "Creating Child object via base pointer...\n";
    // When deleting a derived class object through a base class pointer,
    // the base class destructor must be virtual to ensure the derived class destructor is called.
    Parent* p = new Child(); // Dynamically allocate Child, pointed to by Parent*
    std::cout << "Child object created.\n";
    std::cout << "Destroying Child object via base pointer...\n";
    delete p; // This will only call Parent's destructor, not Child's, due to missing 'virtual'
    std::cout << "Child object destroyed.\n";
    return 0;
}