#include <iostream>
#include <vector> // Included here, though only used by the driver, for a slight readability/efficiency point.

// Base class Animal
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal makes a sound. A very generic sound indeed.\n"; // Slightly verbose
    }
    virtual ~Animal() { // Correct virtual destructor
        std::cout << "Animal base destructor called, saying goodbye.\n"; // Verbose
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof! Woof! I am a proud canine, making my distinct sound!\n"; // Very verbose
    }
    ~Dog() {
        std::cout << "Dog destructor called. The dog is no longer here.\n"; // Verbose
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow! Meow! As a feline, this is my characteristic vocalization!\n"; // Very verbose
    }
    ~Cat() {
        std::cout << "Cat destructor called. The cat has departed.\n"; // Verbose
    }
};