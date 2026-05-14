#include <iostream>
#include <string>

// Abstract base class
class Animal {
public:
    // Pure virtual method
    virtual void makeSound = 0; // Syntax error: missing ()
    virtual ~Animal() {}
};

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // This part of the code will not be reached due to the compilation error
    // Animal* myDog = new Dog();
    // Animal* myCat = new Cat();

    // myDog->makeSound();
    // myCat->makeSound();

    // delete myDog;
    // delete myCat;

    return 0;
}