#include <iostream>

// Abstract base class Animal
class Animal {
public:
    // Pure virtual function makes Animal an abstract class.
    // Any class deriving from Animal must implement makeSound().
    virtual void makeSound() = 0;

    // Virtual destructor is crucial for proper cleanup of derived objects
    // when deleted through a base class pointer.
    virtual ~Animal() = default;
};

// Concrete derived class Dog
class Dog : public Animal {
public:
    // Override makeSound to provide specific behavior for Dog.
    void makeSound() override {
        std::cout << "Woof!\n";
    }
};

// Concrete derived class Cat
class Cat : public Animal {
public:
    // Override makeSound to provide specific behavior for Cat.
    void makeSound() override {
        std::cout << "Meow!\n";
    }
};

int main() {
    // Demonstration of abstract class properties:
    // You cannot instantiate Animal directly. The following line would cause a compile-time error:
    // Animal genericAnimal; // Error: cannot declare variable 'genericAnimal' to be of abstract type 'Animal'
    std::cout << "Attempting to instantiate Animal directly would cause a compile-time error.\n";
    std::cout << "Using Animal pointers to refer to derived objects:\n";

    // Create objects of derived classes on the heap.
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    // Call makeSound() through the base class pointers.
    // Polymorphism ensures the correct derived class function is called.
    myDog->makeSound();
    myCat->makeSound();

    // --- ROBUSTNESS ISSUE: MEMORY LEAK ---
    // The objects allocated with 'new' are not deallocated with 'delete'.
    // This will lead to a memory leak as the memory for myDog and myCat objects
    // is never freed before the program exits.
    // To fix this, 'delete myDog;' and 'delete myCat;' would be needed here.

    return 0;
}