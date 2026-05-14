#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr

// Abstract Animal class
class Animal {
public:
    // Pure virtual function as required
    virtual void makeSound() = 0;

    // Virtual destructor for proper polymorphic cleanup.
    // This ensures that the correct derived class destructor is called
    // when deleting an object through a base class pointer.
    virtual ~Animal() = default;
};

// Dog class deriving from Animal
class Dog : public Animal {
public:
    // Use 'override' keyword for clarity and compile-time checks.
    // This explicitly states the intent to override a base class method.
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

// Cat class deriving from Animal
class Cat : public Animal {
public:
    // Use 'override' keyword for clarity and compile-time checks.
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // Demonstrating proper polymorphic use with smart pointers (std::unique_ptr).
    // This ensures automatic memory management and correct polymorphic destruction
    // due to the virtual destructor in the base class.
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    for (const auto& animal : animals) {
        animal->makeSound();
    }

    // Smart pointers handle memory deallocation automatically when they go out of scope,
    // and the virtual destructor ensures that Dog's and Cat's destructors are called.
    return 0;
}