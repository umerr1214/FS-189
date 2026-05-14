#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr

class Animal {
private:
    std::string species;

public:
    // Parameterized constructor using initializer list and const reference for efficiency
    Animal(const std::string& s) : species(s) {}

    // Virtual method for polymorphic behavior and const-correctness
    virtual void makeSound() const {
        std::cout << "Animal makes a sound. Species: " << species << std::endl;
    }

    // Protected getter for derived classes to access species, maintaining encapsulation
protected:
    const std::string& getSpecies() const { return species; }
};

class Dog : public Animal {
private:
    std::string name;

public:
    // Parameterized constructor: correctly calls base constructor and initializes its own attribute
    // Uses const references and initializer list for efficiency and correctness
    Dog(const std::string& species_val, const std::string& name_val)
        : Animal(species_val), name(name_val) {
        // Constructor body is empty as all initialization is done in the initializer list
    }

    // Override base class method for polymorphic behavior and const-correctness
    void makeSound() const override {
        std::cout << "Woof! My name is " << name << ". Species: " << getSpecies() << "." << std::endl;
    }
};

int main() {
    // Test case 1: Base class object
    Animal genericAnimal("Elephant");
    genericAnimal.makeSound();

    // Test case 2: Derived class object
    Dog myDog("Beagle", "Snoopy");
    myDog.makeSound();

    // Test case 3: Polymorphic behavior using smart pointers for proper memory management
    // std::unique_ptr ensures automatic memory deallocation
    std::unique_ptr<Animal> polyAnimal = std::make_unique<Dog>("Dachshund", "Frank");
    polyAnimal->makeSound(); // Correctly calls Dog::makeSound due to virtual function

    std::unique_ptr<Animal> anotherAnimal = std::make_unique<Animal>("Parrot");
    anotherAnimal->makeSound(); // Calls Animal::makeSound

    return 0;
}