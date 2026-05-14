#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base Constructor called" << std::endl;
    }
    // LOGICAL ERROR: Destructor is NOT virtual.
    // When deleting a Derived object via a Base* pointer, only Base's destructor will be called.
    ~Base() {
        std::cout << "Base Destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor called" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived Destructor called" << std::endl;
    }
};

int main() {
    std::cout << "--- Creating Derived object via Base pointer ---" << std::endl;
    Base* p = new Derived(); // Derived object created, pointed to by Base*
    std::cout << "--- Deleting Derived object via Base pointer ---" << std::endl;
    delete p; // Calls Base::~Base() only, due to non-virtual destructor
    p = nullptr;
    std::cout << "--- End of main ---" << std::endl;
    return 0;
}