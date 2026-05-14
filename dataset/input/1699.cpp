#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but common

// Base class
class Animal {
public:
    std::string species;

    Animal(const std::string& s) : species(s) {
        std::cout << "Animal constructor called for " << species << std::endl;
    }

    // Robustness Issue: Non-virtual destructor
    ~Animal() {
        std::cout << "Animal destructor called for " << species << std::endl;
    }

    void eat() const {
        std::cout << species << " is eating." << std::endl;
    }
};

// Derived class 1
class Mammal : public Animal {
public:
    std::string furColor;

    Mammal(const std::string& s, const std::string& fc)
        : Animal(s), furColor(fc) {
        std::cout << "Mammal constructor called for " << species << " with " << furColor << " fur." << std::endl;
    }

    ~Mammal() {
        std::cout << "Mammal destructor called for " << species << std::endl;
    }

    void giveBirth() const {
        std::cout << species << " is giving birth to live young." << std::endl;
    }
};

// Derived class 2
class Dog : public Mammal {
public:
    std::string breed;

    Dog(const std::string& s, const std::string& fc, const std::string& b)
        : Mammal(s, fc), breed(b) {
        std::cout << "Dog constructor called for " << species << " of breed " << breed << "." << std::endl;
    }

    ~Dog() {
        std::cout << "Dog destructor called for " << species << " (breed: " << breed << ")." << std::endl;
    }

    void bark() const {
        std::cout << species << " (" << breed << ") barks: Woof! Woof!" << std::endl;
    }
};

void run_demonstration() {
    std::cout << "--- Creating a Dog object directly ---" << std::endl;
    Dog myDog("Canine", "Brown", "Golden Retriever");
    myDog.eat();
    myDog.giveBirth();
    myDog.bark();
    std::cout << std::endl;

    std::cout << "--- Demonstrating polymorphic deletion with base pointer (potential issue) ---" << std::endl;
    Animal* polymorphicAnimal = new Dog("Canine", "Black", "Labrador");
    polymorphicAnimal->eat();
    // Cannot call Mammal or Dog specific methods through Animal* without casting
    std::cout << "Deleting Animal* pointer to Dog object..." << std::endl;
    delete polymorphicAnimal; // This will only call Animal's destructor due to non-virtual destructor
    std::cout << "Polymorphic deletion finished." << std::endl;
    std::cout << std::endl;
}

int main() {
    run_demonstration();
    return 0;
}