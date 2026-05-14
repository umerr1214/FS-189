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
        std::cout << "Meow!" << std::endl; // LOGICAL ERROR: Dog makes cat sound
    }
};

// Derived Cat class
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl; // LOGICAL ERROR: Cat makes dog sound
    }
};

int main() {
    Dog myDog;
    Cat myCat;

    Animal* animal1 = &myDog;
    Animal* animal2 = &myCat;

    animal1->makeSound(); // Expected: Woof!, Actual: Meow!
    animal2->makeSound(); // Expected: Meow!, Actual: Woof!

    return 0;
}