#include <iostream>

// Base class definition
class Base {
private: // Semantic Error: Making the constructor private
    Base() {
        std::cout << "Base Constructor Called\n";
    }
public:
    // A public destructor is needed for proper cleanup, even if constructor is private
    ~Base() {
        std::cout << "Base Destructor Called\n";
    }
};

// Derived class definition
class Derived : public Base {
public:
    Derived() {
        // This implicitly tries to call Base::Base(), which is private
        std::cout << "Derived Constructor Called\n";
    }
    ~Derived() {
        std::cout << "Derived Destructor Called\n";
    }
};

int main() {
    std::cout << "Program Start: Creating Derived object...\n";
    { // A block to clearly define the scope of the Derived object
        Derived d; // This line will cause a compilation error
    } // 'd' goes out of scope here, triggering destructors
    std::cout << "Program End: Derived object went out of scope.\n";
    return 0;
}