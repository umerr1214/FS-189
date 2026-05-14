#include <iostream>
#include <vector> // Not strictly needed, but common to include

// Abstract base class
class Animal {
public:
    // Pure virtual method
    virtual void makeSound() = 0;
    
    // !!! ROBUSTNESS ISSUE: Missing virtual keyword for destructor !!!
    // This will lead to undefined behavior/memory leaks if derived objects
    // are deleted through a base class pointer.
    ~Animal() {
        std::cout << "Animal destructor called." << std::endl;
    }
};

// Concrete derived class Dog
class Dog : public Animal {
public:
    Dog() {
        std::cout << "Dog constructor called." << std::endl;
    }
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
    ~Dog() {
        std::cout << "Dog destructor called." << std::endl;
    }
};

// Concrete derived class Cat
class Cat : public Animal {
public:
    Cat() {
        std::cout << "Cat constructor called." << std::endl;
    }
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
    ~Cat() {
        std::cout << "Cat destructor called." << std::endl;
    }
};

// Driver code for testing
int main() {
    std::cout << "--- Creating Animals ---" << std::endl;
    Animal* myDog = new Dog(); // Allocate Dog on heap
    Animal* myCat = new Cat(); // Allocate Cat on heap

    std::cout << "\n--- Animals Making Sounds ---" << std::endl;
    myDog->makeSound();
    myCat->makeSound();

    std::cout << "\n--- Deleting Animals ---" << std::endl;
    // When deleting through a base class pointer without a virtual destructor,
    // only the base class destructor is called. The derived class destructors
    // (Dog::~Dog and Cat::~Cat) are not called, which is a memory leak
    // if derived classes manage resources.
    delete myDog; // Only Animal::~Animal will be called
    delete myCat; // Only Animal::~Animal will be called

    std::cout << "\n--- Program End ---" << std::endl;

    return 0;
}