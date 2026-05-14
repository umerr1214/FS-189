#include <iostream>
#include <string>

// Abstract base class
class Animal {
public:
    // Pure virtual method
    virtual void makeSound() = 0;
    virtual ~Animal() {}
};

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl; // Logical Error: Dog prints Cat's sound
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl; // Logical Error: Cat prints Dog's sound
    }
};

int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    std::cout << "Testing Dog sound: ";
    myDog->makeSound(); // Expected: Woof!, Actual: Meow!

    std::cout << "Testing Cat sound: ";
    myCat->makeSound(); // Expected: Meow!, Actual: Woof!

    delete myDog;
    delete myCat;

    return 0;
}