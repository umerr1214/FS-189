#include <iostream>
#include <string>

// Base class Animal
class Animal {
public:
    std::string name;

    // Inefficient: Passes string by value, causing a copy
    Animal(std::string n) {
        this->name = n; // Redundant 'this->' and assignment after value copy
        std::cout << "Animal named " << name << " is being initialized." << std::endl;
    }

    // Verbose makeSound method
    void makeSound() {
        std::cout << "Animal named " << name << " makes a sound. ";
        std::cout << "This is a very generic sound." << std::endl;
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    // Inefficient: Passes string by value to Animal constructor
    // and also takes by value for its own constructor, potentially
    // causing multiple copies if not optimized by compiler.
    Dog(std::string dogName) : Animal(dogName) {
        // Redundant re-assignment if Animal constructor already set it
        // this->name = dogName; // Could be here as well for more inefficiency
        std::cout << "Dog named " << name << " is being prepared." << std::endl;
    }

    // Overly verbose makeSound method
    void makeSound() {
        std::cout << "Dog named " << name << " makes a sound. ";
        std::cout << "It says: Woof! Woof! ";
        std::cout << "Such a loud bark!" << std::endl;
    }
};

int main() {
    // Create an Animal object
    Animal genericAnimal("Generic");
    genericAnimal.makeSound();

    std::cout << std::endl;

    // Create a Dog object
    Dog myDog("Buddy");
    myDog.makeSound();

    return 0;
}