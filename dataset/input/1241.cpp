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
        std::cout << "Meow!" << std::endl; // Logical error: Dog makes a cat sound
    }
};

// Cat class
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl; // Logical error: Cat makes a dog sound
    }
};

// Main function
int main() {
    std::unique_ptr<Animal> myDog = std::make_unique<Dog>();
    std::unique_ptr<Animal> myCat = std::make_unique<Cat>();

    myDog->makeSound(); // Should output "Woof!", but will output "Meow!"
    myCat->makeSound(); // Should output "Meow!", but will output "Woof!"

    return 0;
}