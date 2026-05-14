#include <iostream>
#include <vector>
#include <string>

// Base Animal class (from Question 11, adapted for this problem)
class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
    // Robustness Issue: Missing virtual destructor.
    // This will lead to a memory leak when deleting derived objects through base pointers.
    ~Animal() {
        std::cout << "Animal destructor called." << std::endl;
    }
};

// Derived Dog class
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
    ~Dog() {
        std::cout << "Dog destructor called." << std::endl;
    }
};

// Derived Cat class
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
    ~Cat() {
        std::cout << "Cat destructor called." << std::endl;
    }
};

int main() {
    // Create an array of Animal pointers
    const int NUM_ANIMALS = 4;
    Animal* animals[NUM_ANIMALS]; // C-style array for simplicity

    // Populate the array with Dog and Cat objects
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    std::cout << "--- Demonstrating Polymorphism ---" << std::endl;
    // Iterate through the array and call makeSound() on each animal
    for (int i = 0; i < NUM_ANIMALS; ++i) {
        std::cout << "Animal " << (i + 1) << ": ";
        animals[i]->makeSound();
    }
    std::cout << "---------------------------------" << std::endl;

    // Clean up dynamically allocated memory
    // Due to the non-virtual destructor in Animal, only Animal's destructor
    // will be called, leading to a memory leak for Dog and Cat objects.
    for (int i = 0; i < NUM_ANIMALS; ++i) {
        delete animals[i];
    }

    std::cout << "\nExplanation of Output:" << std::endl;
    std::cout << "When makeSound() is called, the correct overridden version (from Dog or Cat) is executed." << std::endl;
    std::cout << "This is because the makeSound() method in the Animal base class is declared 'virtual'." << std::endl;
    std::cout << "Even though we are calling it through an 'Animal*' pointer, the runtime type of the object determines which function is invoked (dynamic dispatch)." << std::endl;
    std::cout << "However, observe the destructor calls. Only 'Animal destructor called.' messages appear, not 'Dog destructor called.' or 'Cat destructor called.'." << std::endl;
    std::cout << "This indicates a memory leak: the destructors for the derived Dog and Cat parts of the objects are not being called when deleting through a base pointer, because the Animal base class destructor is not virtual." << std::endl;

    return 0;
}