#include <iostream>
#include <string> // Not strictly necessary for this simple example, but good practice for C++ strings

// Abstract base class Animal
class Animal {
public:
    // Pure virtual function
    virtual void makeSound() = 0;

    // Virtual destructor is crucial for proper cleanup in polymorphic hierarchies
    virtual ~Animal() {
        // std::cout << "Animal destructor called.\n"; // Optional: for debugging
    }
};

// Concrete class Dog
class Dog : public Animal {
public:
    // Implement the pure virtual function
    void makeSound() override {
        std::cout << "Woof!\n";
    }

    // Optional: Dog-specific destructor
    ~Dog() override {
        // std::cout << "Dog destructor called.\n"; // Optional: for debugging
    }
};

// Concrete class Cat
class Cat : public Animal {
public:
    // Implement the pure virtual function
    void makeSound() override {
        std::cout << "Meow!\n";
    }

    // Optional: Cat-specific destructor
    ~Cat() override {
        // std::cout << "Cat destructor called.\n"; // Optional: for debugging
    }
};

int main() {
    // Demonstrate polymorphism using base class pointers
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    // Call makeSound through base class pointers
    myDog->makeSound(); // Calls Dog's makeSound
    myCat->makeSound(); // Calls Cat's makeSound

    // Clean up allocated memory. Virtual destructor ensures correct derived destructors are called.
    delete myDog;
    delete myCat;

    // Can also create objects on the stack (no polymorphism for stack objects usually needed)
    // Dog stackDog;
    // Cat stackCat;
    // stackDog.makeSound();
    // stackCat.makeSound();

    return 0;
}