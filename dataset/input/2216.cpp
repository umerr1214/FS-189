#include <iostream>
#include <string> // Required for std::string

// Abstract base class definition
class Animal {
public:
    // A pure virtual function makes this class abstract.
    virtual void makeSound() = 0;
    // Virtual destructor is crucial for proper cleanup of derived objects through base pointers.
    virtual ~Animal() = default;
};

// Concrete derived class for a Dog
class Dog : public Animal {
public:
    // Implementation of makeSound for Dog.
    // This version uses a less efficient way of printing and
    // unnecessarily flushes the buffer multiple times.
    void makeSound() override {
        std::string dogSound = "Woof!"; // Storing sound in a string first
        // --- READABILITY / EFFICIENCY ISSUE ---
        // Inefficient loop to print character by character, then flush.
        // A simple `std::cout << "Woof!\n";` would be more readable and efficient.
        for (char character : dogSound) {
            std::cout << character; // Print each character individually
        }
        std::cout << std::endl; // Excessive use of std::endl, which flushes the buffer, impacting efficiency.
    }
};

// Concrete derived class for a Cat
class Cat : public Animal {
public:
    // Implementation of makeSound for Cat.
    // Similar readability/efficiency issues as Dog.
    void makeSound() override {
        std::string catSound = "Meow!"; // Storing sound in a string first
        // --- READABILITY / EFFICIENCY ISSUE ---
        // Another inefficient loop and flush.
        for (char character : catSound) {
            std::cout << character; // Print each character individually
        }
        std::cout << std::endl; // Excessive use of std::endl, impacting efficiency.
    }
};

int main() {
    // This line would not compile, demonstrating the abstract nature of Animal.
    // Animal abstractAnimal; // Compiler error: cannot declare variable 'abstractAnimal' to be of abstract type 'Animal'
    std::cout << "Note: Direct instantiation of Animal is not possible (compile-time error).\n" << std::endl;

    // Create objects of derived classes on the stack.
    Dog myDogObject;
    Cat myCatObject;

    // Use Animal pointers to refer to derived objects
    Animal* animalPtr1 = &myDogObject;
    Animal* animalPtr2 = &myCatObject;

    // Call makeSound through the Animal pointers
    std::cout << "Demonstrating sounds via Animal pointers:\n";
    animalPtr1->makeSound(); // Calls Dog's makeSound
    animalPtr2->makeSound(); // Calls Cat's makeSound

    // No memory leak here as objects are on the stack.
    // The main issue is the less efficient and slightly verbose printing in makeSound methods.

    return 0;
}