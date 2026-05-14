#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base Constructor called" << std::endl;
    }
    virtual ~Base() { // Destructor is virtual for correct polymorphic behavior
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
} // SYNTAX ERROR: Missing semicolon here

int main() {
    std::cout << "--- Creating Derived object via Base pointer ---" << std::endl;
    Base* p = new Derived();
    std::cout << "--- Deleting Derived object via Base pointer ---" << std::endl;
    delete p;
    p = nullptr;
    std::cout << "--- End of main ---" << std::endl;
    return 0;
}