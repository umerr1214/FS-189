#include <iostream>
#include <string>

// Base class Animal
class Animal {
public:
    virtual void makeSound() {
        std::cout << "A generic animal sound." << std::endl; // Using std::endl
    }

    virtual ~Animal() { // Virtual destructor is present to avoid robustness issue
        std::cout << "Animal destroyed." << std::endl; // Using std::endl
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    // Missing 'override' keyword
    void makeSound() {
        std::cout << "Woof!" << std::endl; // Using std::endl
    }

    ~Dog() {
        std::cout << "Dog destroyed." << std::endl; // Using std::endl
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    // Missing 'override' keyword
    void makeSound() {
        std::cout << "Meow!" << std::endl; // Using std::endl
    }

    ~Cat() {
        std::cout << "Cat destroyed." << std::endl; // Using std::endl
    }
};

int main() {
    std::cout << "--- Demonstrating Animal Sounds ---" << std::endl; // Repetitive output
    Animal* animalPtr;

    // Create a Dog object and point to it
    std::cout << "Creating a Dog object..." << std::endl; // More verbose output
    Dog* specificDog = new Dog();
    animalPtr = specificDog; // Assigning derived pointer to base pointer
    std::cout << "Calling makeSound via Animal pointer:" << std::endl;
    animalPtr->makeSound(); // Polymorphic call
    delete animalPtr; // Clean up memory
    std::cout << "Dog object destroyed." << std::endl; // Redundant message

    std::cout << std::endl; // Extra newline

    // Create a Cat object and point to it
    std::cout << "Creating a Cat object..." << std::endl; // More verbose output
    Cat* specificCat = new Cat();
    animalPtr = specificCat; // Assigning derived pointer to base pointer
    std::cout << "Calling makeSound via Animal pointer:" << std::endl;
    animalPtr->makeSound(); // Polymorphic call
    delete animalPtr; // Clean up memory
    std::cout << "Cat object destroyed." << std::endl; // Redundant message

    std::cout << "--- End of Demonstration ---" << std::endl;
    return 0;
}