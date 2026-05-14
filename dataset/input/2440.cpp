#include <iostream>
#include <string>

// Abstract Base Class
class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual method
    virtual ~Animal() {} // Virtual destructor for proper cleanup
};

// Derived Dog class
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" std::endl; // SYNTAX ERROR: Missing '<<' operator
    }
};

// Derived Cat class
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // This program will not compile due to the syntax error in Dog::makeSound().
    // If it compiled, a driver might instantiate and call methods like this:
    // Dog myDog;
    // Cat myCat;
    // myDog.makeSound();
    // myCat.makeSound();
    return 0;
}