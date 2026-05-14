#include <iostream>
#include <memory> // For std::unique_ptr for robust memory management

// Abstract base class
class Animal {
public:
    // Pure virtual method, making Animal an abstract class
    virtual void makeSound() = 0;

    // Virtual destructor to ensure proper cleanup of derived objects
    // when deleted through a base class pointer. Using '= default' is clean.
    virtual ~Animal() = default; 
};

// Concrete derived class Dog
class Dog : public Animal {
public:
    // Implement makeSound and use 'override' for clarity and safety
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

// Concrete derived class Cat
class Cat : public Animal {
public:
    // Implement makeSound and use 'override' for clarity and safety
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

// Driver code for testing
int main() {
    std::cout << "--- Creating Animals ---" << std::endl;
    // Using std::unique_ptr for automatic and safe memory management.
    // This correctly handles object lifetime and calls virtual destructors.
    std::unique_ptr<Animal> myDog = std::make_unique<Dog>();
    std::unique_ptr<Animal> myCat = std::make_unique<Cat>();

    std::cout << "\n--- Animals Making Sounds ---" << std::endl;
    myDog->makeSound();
    myCat->makeSound();

    std::cout << "\n--- Deleting Animals (handled by unique_ptr) ---" << std::endl;
    // std::unique_ptr automatically calls destructors when they go out of scope.
    // The virtual destructor in Animal ensures correct derived destructors are called.

    std::cout << "\n--- Program End ---" << std::endl;

    return 0;
}