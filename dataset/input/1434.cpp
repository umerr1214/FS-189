#include <iostream>

class Base {
private: // Semantic error: Base constructor is private, preventing Derived from constructing its Base sub-object.
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
public:
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        // This constructor implicitly tries to call Base's default constructor,
        // but Base's default constructor is private, leading to a compile-time semantic error.
        std::cout << "Derived Constructor" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main() {
    Derived d; // This line will cause a compile-time error due to the private Base constructor.
    return 0;
}