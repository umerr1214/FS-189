#include <iostream>
#include <vector>

// Base class
class Animal {
public:
    // SEMANTIC ERROR: makeSound is not declared virtual.
    // This prevents polymorphic behavior through base class pointers.
    void makeSound() const {
        std::cout << "Animal makes a sound." << std::endl;
    }
    virtual ~Animal() {} // Destructor is virtual for proper cleanup
};

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() const override { // 'override' keyword will cause a compile-time error here
        std::cout << "Dog barks." << std::endl;
    }
    ~Dog() override {}
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() const override { // 'override' keyword will cause a compile-time error here
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
        // Due to makeSound not being virtual in Animal, this will always call Animal::makeSound()
        // even though it's called through a pointer to a derived object.
        animals[i]->makeSound();
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < SIZE; ++i) {
        delete animals[i];
    }

    return 0;
}