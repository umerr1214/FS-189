#include <iostream>

class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Generic animal sound." << std::endl;
    }
    // Semantic error: Destructor is not virtual.
    // This can lead to memory leaks or undefined behavior when deleting derived objects via base pointers.
    ~Animal() {
        // In a real scenario, if Animal had resources, they would be cleaned here.
        // For polymorphic classes, this should be virtual.
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
    ~Dog() {
        // If Dog had unique resources (e.g., dynamically allocated memory),
        // they would not be freed if deleted via an Animal* pointer due to the non-virtual base destructor.
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
    ~Cat() {
        // Similar to Dog, resources in Cat's destructor might not be freed.
    }
};

int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();
    Animal* genericAnimal = new Animal();

    myDog->makeSound();
    myCat->makeSound();
    genericAnimal->makeSound();

    // Due to the non-virtual destructor in Animal, only Animal's destructor will be called
    // for myDog and myCat, potentially leading to resource leaks.
    delete myDog;
    delete myCat;
    delete genericAnimal;

    return 0;
}