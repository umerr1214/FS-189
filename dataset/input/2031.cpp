#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr

// Abstract base class with a pure virtual method and a virtual destructor
class Animal {
public:
    virtual void makeSound() = 0;
    // A virtual destructor ensures proper cleanup of derived objects
    // when deleted through a base class pointer.
    virtual ~Animal() {
        // std::cout << "Animal destructor called." << std::endl; // For tracing
    }
};

// Derived class Dog, overriding makeSound to print its sound directly
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
    ~Dog() override {
        // std::cout << "Dog destructor called." << std::endl; // For tracing
    }
};

// Derived class Cat, overriding makeSound to print its sound directly
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
    ~Cat() override {
        // std::cout << "Cat destructor called." << std::endl; // For tracing
    }
};

int main() {
    // Using std::vector of std::unique_ptr for automatic, safe, and efficient
    // memory management of polymorphic objects.
    std::vector<std::unique_ptr<Animal>> animals;

    // Add instances of derived classes using std::make_unique
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    std::cout << "Animals making sounds:" << std::endl;
    // Iterate and call makeSound polymorphically
    for (const auto& animal : animals) {
        animal->makeSound();
    }
    std::cout << std::endl;

    // std::unique_ptr automatically handles object deletion when they go out of scope
    // (at the end of main), ensuring proper cleanup through the virtual destructor.
    std::cout << "All animals have made their sounds and will be automatically cleaned up." << std::endl;

    return 0;
}