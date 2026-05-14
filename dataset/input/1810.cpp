#include <iostream>

class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Generic animal sound." << std::endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" // Missing semicolon here
    }
    virtual ~Dog() {}
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
    virtual ~Cat() {}
};

int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();
    Animal* genericAnimal = new Animal();

    myDog->makeSound();
    myCat->makeSound();
    genericAnimal->makeSound();

    delete myDog;
    delete myCat;
    delete genericAnimal;

    return 0;
}