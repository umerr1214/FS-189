#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base Constructor\n"; // Efficiently uses '\n' instead of std::endl
    }
    // Correct Version: Destructor is virtual to ensure correct polymorphic destruction.
    virtual ~Base() {
        std::cout << "Base Destructor\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor\n";
    }
    // Good practice: using 'override' explicitly indicates that this function overrides a virtual function.
    ~Derived() override {
        std::cout << "Derived Destructor\n";
    }
};

int main() {
    // Observe construction and destruction order using a dynamically allocated object
    // and a base class pointer to demonstrate the full lifecycle in a polymorphic context.
    std::cout << "Creating a Derived object via Base pointer (Correct Version):\n";
    Base* objPtr = new Derived();

    std::cout << "Deleting the object via Base pointer:\n";
    // Correctly calls Derived's destructor first, then Base's destructor,
    // due to the virtual destructor in the Base class.
    delete objPtr; 

    std::cout << "Observation complete.\n";

    return 0;
}