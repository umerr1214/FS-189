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
    // No getter for species is provided, to ensure the semantic error below.
};

// Derived class Dog
class Dog : public Animal {
private:
    std::string name;

public:
    Dog(const std::string& s, const std::string& n) : Animal(s), name(n) {}

    void makeSound() const override {
        // Semantic Error: Attempting to access the private member 'species'
        // directly from the base class 'Animal'. This is a compile-time access violation.
        std::cout << name << " the " << species << " barks." << std::endl;
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