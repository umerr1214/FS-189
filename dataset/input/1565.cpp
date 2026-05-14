#include <iostream>
#include <vector>

// Base class
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal makes a sound." << std::endl;
    }
    virtual ~Animal() {}
};

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
    // LOGICAL ERROR: Creating an array of Animal objects, not Animal pointers.
    // This will lead to object slicing when Dog/Cat objects are assigned,
    // losing their derived class specific behavior.
    Animal animals[SIZE];

    // Objects are sliced here. Only the Animal part is copied.
    animals[0] = Dog();
    animals[1] = Cat();
    animals[2] = Dog();

    for (int i = 0; i < SIZE; ++i) {
        // This will always call Animal::makeSound() due to slicing.
        animals[i].makeSound();
    }

    // No dynamic memory to clean up in this incorrect scenario

    return 0;
}