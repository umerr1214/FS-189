#include <iostream>

// Base class Animal
class Animal {
public:
    // Virtual method to demonstrate polymorphism
    virtual void makeSound() {
        std::cout << "Animal makes a sound.\n";
    }

    // NON-VIRTUAL destructor: This is the robustness issue.
    // When a derived object is deleted through a base class pointer,
    // only the base class destructor will be called, leading to
    // a memory leak if derived classes have specific resources to free.
    ~Animal() {
        std::cout << "Animal destructor called.\n";
    }
};

// Derived class Dog
class Dog : public Animal {
public:
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
    void makeSound() override {
        std::cout << "Meow!\n";
    }

    ~Cat() {
        std::cout << "Cat destructor called.\n";
    }
};