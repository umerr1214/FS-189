#include <iostream>
#include <string>

// Base class Animal without a virtual destructor
class Animal {
public:
    virtual void makeSound() {
        std::cout << "A generic animal sound.\n";
    }

    // Missing virtual destructor - this is the robustness issue
    ~Animal() {
        std::cout << "Animal destroyed.\n";
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!\n";
    }

    ~Dog() {
        std::cout << "Dog destroyed.\n";
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!\n";
    }

    ~Cat() {
        std::cout << "Cat destroyed.\n";
    }
};

int main() {
    Animal* myAnimal;

    // Demonstrate with Dog
    myAnimal = new Dog(); // Dynamically allocate a Dog object
    myAnimal->makeSound(); // Calls Dog's makeSound() polymorphically
    delete myAnimal; // Deleting via base pointer without virtual destructor

    std::cout << "\n"; // Separator for clarity

    // Demonstrate with Cat
    myAnimal = new Cat(); // Dynamically allocate a Cat object
    myAnimal->makeSound(); // Calls Cat's makeSound() polymorphically
    delete myAnimal; // Deleting via base pointer without virtual destructor

    return 0;
}