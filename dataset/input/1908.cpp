#include <iostream>

class Base {
private:
    // SEMANTIC ERROR: Making the destructor private prevents deletion via Base*
    // because 'delete' implicitly calls the destructor, which is inaccessible.
    virtual ~Base() {
        std::cout << "Base Destructor called" << std::endl;
    }
public:
    Base() {
        std::cout << "Base Constructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor called" << std::endl;
    }
    // Derived's destructor implicitly tries to call Base's private destructor,
    // which makes this destructor definition or its usage problematic.
    ~Derived() {
        std::cout << "Derived Destructor called" << std::endl;
    }
};

int main() {
    std::cout << "--- Creating Derived object via Base pointer ---" << std::endl;
    Base* p = new Derived(); // Object creation succeeds
    std::cout << "--- Deleting Derived object via Base pointer ---" << std::endl;
    delete p; // SEMANTIC ERROR: Attempting to call private Base::~Base()
    p = nullptr;
    std::cout << "--- End of main ---" << std::endl;
    return 0;
}