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
        std::cout << "Woof!\n"; // Efficiently prints the sound followed by a newline.
    }
};

// Concrete derived class Cat
class Cat : public Animal {
public:
    // Override makeSound to provide specific behavior for Cat.
    void makeSound() override {
        std::cout << "Meow!\n"; // Efficiently prints the sound followed by a newline.
    }
};

int main() {
    // Demonstration of abstract class properties:
    // You cannot instantiate Animal directly. The following line would cause a compile-time error:
    // Animal genericAnimal; // Error: cannot declare variable 'genericAnimal' to be of abstract type 'Animal'
    std::cout << "Attempting to instantiate 'Animal' directly would result in a compile-time error.\n";
    std::cout << "This demonstrates that 'Animal' is an abstract base class.\n\n";

    std::cout << "Now demonstrating polymorphism using 'Animal' pointers:\n";

    // Create objects of derived classes on the heap.
    Animal* dogPtr = new Dog();
    Animal* catPtr = new Cat();

    // Call makeSound() through the base class pointers.
    // Polymorphism ensures the correct derived class function is called.
    std::cout << "Dog says: ";
    dogPtr->makeSound();

    std::cout << "Cat says: ";
    catPtr->makeSound();

    // Clean up dynamically allocated memory to prevent leaks.
    // This is essential when using raw pointers with 'new'.
    delete dogPtr;
    delete catPtr;

    std::cout << "\nDemonstration complete. Objects cleaned up.\n";

    return 0;
}