#include <iostream>
#include <string>

// Animal (base)
class Animal {
private: // Making species private
    std::string species;
public:
    Animal(std::string s) : species(s) {}
    void eat() const {
        std::cout << species << " is eating." << std::endl;
    }
    virtual void makeSound() const {
        std::cout << species << " makes a sound." << std::endl;
    }
    void sleep() const {
        std::cout << species << " is sleeping." << std::endl;
    }
    // Added a public getter for species for valid access from derived classes or main
    std::string getSpecies() const {
        return species;
    }
};

// Mammal (derived from Animal)
class Mammal : public Animal {
public:
    std::string furColor;
    // This is still valid as it calls the public Animal constructor
    Mammal(std::string s, std::string fc) : Animal(s), furColor(fc) {}
    void lactate() const {
        // Accessing species via getter, which is valid
        std::cout << getSpecies() << " (a mammal) is lactating." << std::endl;
    }
    void makeSound() const override {
        std::cout << getSpecies() << " (mammal) makes a distinct sound." << std::endl;
    }
};

// Dog (derived from Mammal)
class Dog : public Mammal {
public:
    std::string breed;
    Dog(std::string s, std::string fc, std::string b) : Mammal(s, fc), breed(b) {}
    void bark() const {
        std::cout << breed << " the " << getSpecies() << " barks: Woof! Woof!" << std::endl;
    }
    void makeSound() const override {
        std::cout << breed << " the " << getSpecies() << " says: Bark! Bark!" << std::endl;
    }
    void fetch() const {
        std::cout << breed << " the " << getSpecies() << " is fetching." << std::endl;
    }
};

int main() {
    // Object creation and method calls
    Animal genericAnimal("Generic Creature");
    std::cout << "--- Animal ---" << std::endl;
    genericAnimal.eat();
    genericAnimal.makeSound();
    genericAnimal.sleep();
    // Semantic Error: Attempting to access private member 'species' directly
    std::cout << genericAnimal.species << std::endl; // ERROR LINE
    std::cout << std::endl;

    Mammal lion("Lion", "Golden");
    std::cout << "--- Mammal ---" << std::endl;
    lion.eat();
    lion.makeSound();
    lion.sleep();
    lion.lactate();
    std::cout << std::endl;

    Dog labrador("Labrador Retriever", "Yellow", "Labrador");
    std::cout << "--- Dog ---" << std::endl;
    labrador.eat();
    labrador.makeSound();
    labrador.sleep();
    labrador.lactate();
    labrador.bark();
    labrador.fetch();
    std::cout << std::endl;

    return 0;
}