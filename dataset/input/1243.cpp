#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr

// Abstract Animal class
class Animal {
public:
    // Pure virtual function
    virtual void makeSound() = 0;

    // ROBUSTNESS ISSUE: Missing virtual destructor.
    // This can lead to undefined behavior or resource leaks
    // when deleting derived objects through a base class pointer.
    ~Animal() {
        // In a more complex scenario, if Animal had resources,
        // they might not be properly cleaned up polymorphically.
        // For simple classes like this, it might not crash, but it's a design flaw.
    }
};

// Dog class
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
    // Destructor for Dog (will only be called if deleted via Dog* or if Animal's destructor is virtual)
    ~Dog() {
        // std::cout << "Dog destructor called." << std::endl; // For observation
    }
};

// Cat class
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
    // Destructor for Cat (will only be called if deleted via Cat* or if Animal's destructor is virtual)
    ~Cat() {
        // std::cout << "Cat destructor called." << std::endl; // For observation
    }
};

int main() {
    // Using unique_ptr to manage object lifetimes.
    // If Animal's destructor were virtual, unique_ptr would correctly call
    // the derived class destructor followed by the base class destructor.
    // Without it, only ~Animal() is guaranteed to be called polymorphically.
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    for (const auto& animal : animals) {
        animal->makeSound();
    }

    // When 'animals' vector goes out of scope, unique_ptr elements are destroyed.
    // Due to the non-virtual destructor in Animal, the destructors of Dog and Cat
    // are not guaranteed to be called, which is a robustness issue for polymorphic classes.

    return 0;
}