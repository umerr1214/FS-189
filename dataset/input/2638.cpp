#include <iostream>
#include <string>

// Base class Animal
class Animal // Syntax Error: Missing semicolon after class definition
{
private:
    std::string species;

public:
    Animal(const std::string& s) : species(s) {}

    virtual void makeSound() const {
        std::cout << "An " << species << " makes a sound." << std::endl;
    }

    // A getter is included for potential use in derived classes or testing, if the error were elsewhere.
    const std::string& getSpecies() const {
        return species;
    }
};

// Derived class Dog
class Dog : public Animal {
private:
    std::string name;

public:
    Dog(const std::string& s, const std::string& n) : Animal(s), name(n) {}

    void makeSound() const override {
        std::cout << name << " the " << getSpecies() << " barks." << std::endl;
    }
};

// Driver code
int main() {
    Animal genericAnimal("bear");
    genericAnimal.makeSound();

    Dog myDog("Labrador", "Buddy");
    myDog.makeSound();

    Animal* anotherDog = new Dog("Poodle", "Fido");
    anotherDog->makeSound();
    delete anotherDog;

    return 0;
}