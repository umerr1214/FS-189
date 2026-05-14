#include <iostream>

// Base class Animal
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal makes a sound.\n";
    }
    // Virtual destructor is crucial for correct memory cleanup with polymorphism
    virtual ~Animal() {
        std::cout << "Animal base destructor called.\n";
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    // Using 'override' keyword for clarity and compile-time checking
    void makeSound() override {
        std::cout << "Woof!\n";
    }
    ~Dog() {
        std::cout << "Dog destructor called.\n";
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    // Using 'override' keyword
    void makeSound() override {
        std::cout << "Meow!\n";
    }
    ~Cat() {
        std::cout << "Cat destructor called.\n";
    }
};