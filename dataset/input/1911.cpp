#include <iostream>
#include <memory> // Required for std::unique_ptr

// Base class
class Base {
public:
    Base() {
        std::cout << "Base Constructor Called\n";
    }

    // Virtual destructor is crucial for proper polymorphic destruction
    virtual ~Base() {
        std::cout << "Base Destructor Called\n";
    }
};

// Derived class
class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor Called\n";
    }

    // Using 'override' keyword for clarity and compile-time checking
    ~Derived() override {
        std::cout << "Derived Destructor Called\n";
    }
};

int main() {
    std::cout << "Creating Derived object via Base unique_ptr...\n";

    // Use std::unique_ptr for automatic memory management and modern C++ best practices.
    // When 'ptr' goes out of scope, the destructor will be called automatically and correctly.
    std::unique_ptr<Base> ptr = std::make_unique<Derived>();

    std::cout << "Object created. 'ptr' will be deleted when it goes out of scope.\n";
    // The object pointed to by 'ptr' is automatically deleted here as 'ptr' goes out of scope.
    // Due to the virtual destructor in Base, the Derived destructor will be called first,
    // followed by the Base destructor.

    std::cout << "Demonstration complete.\n";

    return 0;
}