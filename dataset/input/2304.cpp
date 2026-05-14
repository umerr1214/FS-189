#include <iostream>

class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() = default;
};

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
    // Semantic Error: Attempting to instantiate an abstract class
    // This line will cause a compilation error because Animal is abstract
    // Animal myAnimal; 

    Dog myDog;
    Cat myCat;

    Animal* animal1 = &myDog;
    Animal* animal2 = &myCat;

    animal1->makeSound();
    animal2->makeSound();

    return 0;
}