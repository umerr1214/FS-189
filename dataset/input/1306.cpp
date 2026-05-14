#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    // Non-virtual destructor - demonstrating the problem scenario
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
}; // Missing semicolon here, causing a syntax error

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived Destructor" << std::endl;
    }
};

void demonstrate_non_virtual_problem() {
    std::cout << "--- Demonstrating non-virtual destructor problem ---" << std::endl;
    Base* ptr = new Derived(); // Base pointer to Derived object
    delete ptr; // Deleting through base pointer without virtual destructor
                // will only call Base's destructor, leading to Derived's part not being destructed.
    std::cout << "----------------------------------------------------" << std::endl;
}

int main() {
    demonstrate_non_virtual_problem();
    return 0;
}