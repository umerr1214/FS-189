#include <iostream>
#include <string>

// Abstract base class Animal
class Animal {
public:
    // Pure virtual function
    virtual void makeSound() = 0;

    // Missing virtual destructor - this is the robustness issue
    ~Animal() {
        // std::cout << "Animal destructor called.\n"; // For debugging if needed
    }
};

// Concrete class Dog
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!\n";
    }
};

// Concrete class Cat
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!\n";
    }
};

int main() {
    // Demonstrate polymorphism
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    myDog->makeSound(); // Dog makes sound
    myCat->makeSound(); // Cat makes sound

    // Deleting derived objects via base pointers.
    // Without a virtual destructor in Animal, this leads to undefined behavior
    // or memory leaks for resources specific to derived classes.
    delete myDog;
    delete myCat;

    return 0;
}