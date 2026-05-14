#include <iostream>
#include <string>

// Base class Animal
class Animal {
private:
    std::string species;

public:
    Animal(const std::string& s) : species(s) {}

    virtual void makeSound() const {
        std::cout << "An " << species << " makes a sound." << std::endl;
    }

    const std::string& getSpecies() const {
        return species;
    }
};

// Derived class Dog
class Dog : public Animal {
private:
    std::string name;

public:
    // Logical Error: The Dog constructor incorrectly passes a hardcoded string "Canine"
    // to the base Animal constructor instead of the provided 's' parameter.
    Dog(const std::string& s, const std::string& n) : Animal("Canine"), name(n) {} // Should be Animal(s)

    void makeSound() const override {
        std::cout << name << " the " << getSpecies() << " barks." << std::endl;
    }
};

// Driver code
int main() {
    Animal genericAnimal("bear");
    genericAnimal.makeSound(); // Correct: An bear makes a sound.

    Dog myDog("Labrador", "Buddy");
    myDog.makeSound(); // Incorrect: Buddy the Canine barks. (Should be Labrador)

    Animal* anotherDog = new Dog("Poodle", "Fido");
    anotherDog->makeSound(); // Incorrect: Fido the Canine barks. (Should be Poodle)
    delete anotherDog;

    return 0;
}