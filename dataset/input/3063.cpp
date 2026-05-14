#include <iostream>
#include <string>

// Base class Animal
class Animal {
public:
    // Virtual method for polymorphic behavior
    virtual void makeSound() const {
        std::cout << "A generic animal sound.\n";
    }

    // Virtual destructor for proper polymorphic cleanup
    virtual ~Animal() {
        std::cout << "Animal destroyed.\n";
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    // Override makeSound method, using 'override' keyword and 'const'
    void makeSound() const override {
        std::cout << "Woof!\n";
    }

    ~Dog() {
        std::cout << "Dog destroyed.\n";
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    // Override makeSound method, using 'override' keyword and 'const'
    void makeSound() const override {
        std::cout << "Meow!\n";
    }

    ~Cat() {
        std::cout << "Cat destroyed.\n";
    }
};

int main() {
    // Pointer to base class
    Animal* myAnimalPtr = nullptr;

    // Demonstrate with a Dog object
    myAnimalPtr = new Dog(); // Animal pointer points to a Dog object
    myAnimalPtr->makeSound(); // Calls Dog's makeSound() due to polymorphism
    delete myAnimalPtr;      // Calls Dog's destructor, then Animal's destructor
    myAnimalPtr = nullptr;   // Good practice to nullify pointer after deletion

    std::cout << "\n"; // Separator for clarity

    // Demonstrate with a Cat object
    myAnimalPtr = new Cat(); // Animal pointer points to a Cat object
    myAnimalPtr->makeSound(); // Calls Cat's makeSound() due to polymorphism
    delete myAnimalPtr;      // Calls Cat's destructor, then Animal's destructor
    myAnimalPtr = nullptr;   // Good practice to nullify pointer after deletion

    return 0;
}