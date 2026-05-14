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
        std::cout << "Woof!" << std::endl;
    }
    virtual ~Dog() {}
};

class Cat : public Animal {
public:
    void makeSound() const override {
        // Logical error: Cat::makeSound() prints the generic sound instead of "Meow!".
        std::cout << "Generic animal sound." << std::endl;
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