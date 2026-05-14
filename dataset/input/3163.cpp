#include <iostream>
#include <string>

// Base class Animal
class Animal {
public:
    std::string name;

    Animal(std::string n) : name(n) {
        std::cout << "Animal " << name << " created." << std::endl;
    }

    // Base class makeSound method
    void makeSound() {
        std::cout << "Generic animal " << name << " makes a sound: Generic animal sound." << std::endl;
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {
        std::cout << "Dog " << name << " created." << std::endl;
    }

    // Overrides makeSound without using virtual (static dispatch)
    void makeSound() {
        std::cout << "Dog " << name << " makes a sound: Woof!" << std::endl;
    }
};

int main() {
    // Create an Animal object
    Animal genericAnimal("Generic");
    genericAnimal.makeSound(); // Calls Animal::makeSound()

    std::cout << std::endl;

    // Create a Dog object
    Dog myDog("Buddy");
    myDog.makeSound(); // Calls Dog::makeSound()

    std::cout << std::endl;

    // Demonstrate robustness issue:
    // When a derived class object is accessed via a base class pointer/reference
    // without virtual functions, the base class method is called.
    // This can lead to unexpected behavior if polymorphic dispatch is desired.

    Animal* animalPtr = &myDog; // Animal pointer to a Dog object
    std::cout << "Using Animal pointer to Dog:" << std::endl;
    animalPtr->makeSound(); // STILL calls Animal::makeSound(), not Dog::makeSound()

    std::cout << std::endl;

    Animal& animalRef = myDog; // Animal reference to a Dog object
    std::cout << "Using Animal reference to Dog:" << std::endl;
    animalRef.makeSound(); // STILL calls Animal::makeSound(), not Dog::makeSound()

    return 0;
}