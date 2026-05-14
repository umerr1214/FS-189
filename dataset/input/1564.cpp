#include <iostream>
#include <vector>

// Base class
class Animal
{
public:
    virtual void makeSound() const {
        std::cout << "Animal makes a sound." << std::endl;
    }
    virtual ~Animal() {}
} // SYNTAX ERROR: Missing semicolon here

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Dog barks." << std::endl;
    }
    ~Dog() override {}
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Cat meows." << std::endl;
    }
    ~Cat() override {}
};

int main() {
    const int SIZE = 3;
    Animal* animals[SIZE];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();

    for (int i = 0; i < SIZE; ++i) {
        animals[i]->makeSound();
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < SIZE; ++i) {
        delete animals[i];
    }

    return 0;
}