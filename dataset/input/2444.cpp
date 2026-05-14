#include <iostream> // Include for input/output operations
#include <string>   // Include for string manipulation (not strictly needed here but often included)
#include <vector>   // Include for vector (not strictly needed here but often included)

// Using the entire std namespace globally is generally considered a readability issue
// in larger projects as it can lead to name collisions.
using namespace std;

// Abstract base class for animals
class Animal {
public:
    // This is a pure virtual function, meaning derived classes MUST implement it.
    virtual void makeSound() = 0;

    // A default destructor is fine, but for polymorphism, a virtual destructor is usually better practice.
    // However, for this specific problem where no resources are managed, it's not a correctness issue.
    // Not marking it virtual is a minor readability/best practice omission in a polymorphic base class.
    ~Animal() {
        // Simple destructor for the Animal class.
        // It doesn't do much, but it's here.
    }
};

// Derived class representing a Dog
class Dog : public Animal {
public:
    // Implementation of the makeSound method for Dog.
    // Using std::endl flushes the buffer, which is less efficient than '\n'
    // if not explicitly needed, making it a minor efficiency issue.
    // Also, the method is not marked 'const', even though it doesn't modify the object,
    // which is a minor readability/best practice omission.
    void makeSound() override {
        cout << "Woof!" << endl; // Inefficient use of endl
    }
};

// Derived class representing a Cat
class Cat : public Animal {
public:
    // Implementation of the makeSound method for Cat.
    // Similar to Dog, uses std::endl and is not marked 'const'.
    void makeSound() override {
        cout << "Meow!" << endl; // Inefficient use of endl
    }
};

// Main function where the program execution begins
int main() {
    // Creating objects of derived classes
    Dog myDog; // Stack allocation
    Cat myCat; // Stack allocation

    // Using a base class pointer to demonstrate polymorphism
    // This is a common C++ pattern for handling objects polymorphically.
    Animal* animalPtr1 = &myDog; // Pointer to Dog object
    Animal* animalPtr2 = &myCat; // Pointer to Cat object

    // Call makeSound through the base class pointers
    // The specific makeSound implementation (Dog's or Cat's) will be called.
    cout << "A dog says: ";
    animalPtr1->makeSound(); // This will call Dog::makeSound()

    cout << "A cat says: ";
    animalPtr2->makeSound(); // This will call Cat::makeSound()

    // The program ends here. Stack allocated objects are automatically cleaned up.
    return 0; // Indicate successful execution
}