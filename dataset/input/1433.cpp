#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main() {
    Base b; // Logical error: Only a Base object is created, not a Derived object, so the full inheritance construction/destruction order is not observed.
    return 0;
}