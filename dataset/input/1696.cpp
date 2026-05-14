#include <iostream>
#include <string>

// Animal (base)
class Animal {
public:
    std::string species;
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
} // SYNTAX ERROR: Missing semicolon here

// Mammal (derived from Animal)
class Mammal : public Animal {
public:
    std::string furColor;
    Mammal(std::string s, std::string fc) : Animal(s), furColor(fc) {}
    void lactate() const {
        std::cout << species << " (a mammal) is lactating." << std::endl;
    }
    void makeSound() const override { // Overrides Animal's makeSound
        std::cout << species << " (mammal) makes a distinct sound." << std::endl;
    }
};

// Dog (derived from Mammal)
class Dog : public Mammal {
public:
    std::string breed;
    Dog(std::string s, std::string fc, std::string b) : Mammal(s, fc), breed(b) {}
    void bark() const {
        std::cout << breed << " the " << species << " barks: Woof! Woof!" << std::endl;
    }
    void makeSound() const override { // Overrides Mammal's makeSound
        std::cout << breed << " the " << species << " says: Bark! Bark!" << std::endl;
    }
    void fetch() const {
        std::cout << breed << " the " << species << " is fetching." << std::endl;
    }
};

int main() {
    // Object creation and method calls
    Animal genericAnimal("Generic Creature");
    std::cout << "--- Animal ---" << std::endl;
    genericAnimal.eat();
    genericAnimal.makeSound();
    genericAnimal.sleep();
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