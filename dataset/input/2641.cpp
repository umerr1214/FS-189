#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr

class Animal {
private:
    std::string species;

public:
    Animal(std::string s) : species(s) {}

    // Robustness Issue: makeSound is not virtual.
    // This prevents proper polymorphic behavior when a derived class object
    // is accessed via a base class pointer or reference.
    void makeSound() const {
        std::cout << "Animal makes a generic sound. Species: " << species << std::endl;
    }

protected:
    // Providing a protected getter allows derived classes to access species
    // while keeping it private in the base class.
    const std::string& getSpecies() const { return species; }
};

class Dog : public Animal {
private:
    std::string name;

public:
    // Dog constructor correctly calls Animal constructor and initializes its own name.
    Dog(std::string species_val, std::string name_val)
        : Animal(species_val), name(name_val) {}

    // This method is intended to override Animal::makeSound,
    // but without 'virtual' in the base class, it's just a new method in Dog.
    void makeSound() const {
        std::cout << "Woof! My name is " << name << ". (Species initialized in base: " << getSpecies() << ")" << std::endl;
    }
};

int main() {
    // Test case 1: Base class object
    Animal genericAnimal("Lion");
    genericAnimal.makeSound(); // Calls Animal::makeSound

    // Test case 2: Derived class object
    Dog myDog("Golden Retriever", "Buddy");
    myDog.makeSound(); // Calls Dog::makeSound

    // Test case 3: Demonstrating the robustness issue
    // An Animal pointer pointing to a Dog object.
    // Because Animal::makeSound is not virtual, this will call Animal::makeSound,
    // NOT Dog::makeSound, which is usually not the desired polymorphic behavior.
    std::unique_ptr<Animal> polymorphicAnimal = std::make_unique<Dog>("Labrador", "Max");
    polymorphicAnimal->makeSound(); // Robustness issue: Calls Animal::makeSound
                                    // Expected Dog::makeSound but got Animal::makeSound

    return 0;
}