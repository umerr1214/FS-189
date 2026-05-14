#include <iostream> // Include necessary header for input/output operations

// Base class Animal
class Animal {
public:
    // Virtual method to allow polymorphic behavior.
    // Declared 'const' as it does not modify the object's state.
    virtual void sound() const {
        std::cout << "Generic animal sound." << '\n'; // Using '\n' for efficiency
    }

    // Virtual destructor is good practice for polymorphic base classes
    // to ensure proper cleanup of derived objects when deleted via a base pointer.
    virtual ~Animal() = default;
};

// Derived class Dog, publicly inheriting from Animal
class Dog : public Animal {
public:
    // Override the sound method for Dog.
    // 'override' keyword ensures that the method correctly overrides a base class virtual method.
    void sound() const override {
        std::cout << "Woof!" << '\n';
    }
};

// Derived class Cat, publicly inheriting from Animal
class Cat : public Animal {
public:
    // Override the sound method for Cat.
    void sound() const override {
        std::cout << "Meow!" << '\n';
    }
};

// Main function to demonstrate the hierarchical inheritance
int main() {
    // Create objects of derived classes and a base class object
    Dog myDog;
    Cat myCat;
    Animal genericAnimal; // It's also possible to instantiate the base class

    // Use base class pointers to demonstrate polymorphism
    // Pointers to Animal can point to Dog or Cat objects
    Animal* animalPtrForDog = &myDog;
    Animal* animalPtrForCat = &myCat;
    Animal* animalPtrForGeneric = &genericAnimal;

    std::cout << "--- Demonstrating hierarchical inheritance with polymorphism ---\n";

    // Call sound method polymorphically using base class pointers
    // Due to 'virtual' keyword, the correct derived method is called.
    animalPtrForDog->sound();     // Calls Dog::sound()
    animalPtrForCat->sound();     // Calls Cat::sound()
    animalPtrForGeneric->sound(); // Calls Animal::sound()

    std::cout << "\n--- Direct object calls for comparison ---\n";
    // Direct calls to confirm behavior
    myDog.sound();
    myCat.sound();
    genericAnimal.sound();

    return 0; // Indicate successful execution
}