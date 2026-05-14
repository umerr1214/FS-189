#include <iostream>

class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() = default;
}; // Syntax Error: Missing semicolon after class definition

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Dog myDog;
    Cat myCat;

    Animal* animal1 = &myDog;
    Animal* animal2 = &myCat;

    animal1->makeSound();
    animal2->makeSound();

    return 0;
}