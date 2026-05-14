#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr
#include <vector>

// Abstract base class Animal
class Animal {
public:
    // Pure virtual method
    virtual void makeSound() = 0;

    // Virtual destructor is crucial for proper cleanup of derived objects
    // when deleted via a base class pointer.
    virtual ~Animal() {
        // std::cout << "Animal destructor called." << std::endl;
    }
};

// Concrete class Dog
class Dog : public Animal {
public:
    // Using 'override' keyword for clarity and compile-time checking
    void makeSound() override {
        std::cout << "Woof! Woof!" << std::endl;
    }

    ~Dog() override {
        // std::cout << "Dog destructor called." << std::endl;
    }
};

// Concrete class Cat
class Cat : public Animal {
public:
    // Using 'override' keyword
    void makeSound() override {
        std::cout << "Meow! Purrr." << std::endl;
    }

    ~Cat() override {
        // std::cout << "Cat destructor called." << std::endl;
    }
};

int main() {
    // Using std::unique_ptr for automatic and safe memory management
    // This demonstrates proper polymorphic behavior and resource handling.
    std::vector<std::unique_ptr<Animal>> farm_animals;

    farm_animals.push_back(std::make_unique<Dog>());
    farm_animals.push_back(std::make_unique<Cat>());
    farm_animals.push_back(std::make_unique<Dog>()); // Another dog

    for (const auto& animal : farm_animals) {
        animal->makeSound();
    }

    // Objects are automatically deleted when farm_animals goes out of scope
    // thanks to std::unique_ptr and the virtual destructor in Animal.

    std::cout << "--- Stack-allocated animals ---" << std::endl;
    // For simple cases, stack allocation is also perfectly fine and efficient
    Dog stack_dog;
    Cat stack_cat;
    stack_dog.makeSound();
    stack_cat.makeSound();

    return 0;
}