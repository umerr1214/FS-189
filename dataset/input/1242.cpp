#include <iostream>
#include <vector>
#include <memory> // For smart pointers

// Abstract Animal class
class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual
    virtual ~Animal() {} // Virtual destructor
};

// Dog class
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

// Cat class
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

// Main function
int main() {
    // SEMANTIC ERROR: Attempting to instantiate an abstract class directly.
    // This line will cause a compilation error as 'Animal' is an abstract class.
    Animal myAnimal; // This is the semantic error.
    // The following line would also be problematic if the above compiled.
    myAnimal.makeSound();

    std::unique_ptr<Animal> myDog = std::make_unique<Dog>();
    std::unique_ptr<Animal> myCat = std::make_unique<Cat>();

    myDog->makeSound();
    myCat->makeSound();

    return 0;
}