#include <iostream>
#include <vector>

class Animal {
public:
    virtual void makeSound() {
        std::cout << "Generic animal sound." << std::endl;
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void makeSound() override {
        // Logical error: Dog prints Cat's sound instead of its own
        std::cout << "Meow!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    std::cout << "Dog says: ";
    myDog->makeSound();

    std::cout << "Cat says: ";
    myCat->makeSound();

    delete myDog;
    delete myCat;

    return 0;
}