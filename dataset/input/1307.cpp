#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    // Non-virtual destructor - this is the source of the problem
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
    std::cout << "Illustrating non-virtual destructor leading to memory issue:" << std::endl;
    Base* ptr = new Derived(); // Base pointer to Derived object
    delete ptr; // Deleting through base pointer without virtual destructor
                // will only call Base's destructor, leading to Derived's part not being destructed.
    std::cout << "Note: Only Base Destructor was called. Derived Destructor was skipped." << std::endl;
    std::cout << "The program did not proceed to demonstrate the fix as required by the question." << std::endl; // Logical Error: Incomplete solution
    return 0;
}