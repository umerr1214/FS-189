#include <iostream>
#include <string>
#include <vector>

// Abstract base class Animal
class Animal {
public:
    // Pure virtual method
    virtual void makeSound() = 0;

    // NON-VIRTUAL destructor - This is the robustness issue.
    // If a derived object is deleted via a base class pointer,
    // only the base class destructor will be called,
    // leading to potential resource leaks or undefined behavior
    // if derived classes have specific cleanup logic.
    ~Animal() {
        std::cout << "Animal destructor called." << std::endl;
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }

    // Add a destructor to demonstrate the issue
    ~Dog() {
        std::cout << "Dog destructor called." << std::endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }

    // Add a destructor to demonstrate the issue
    ~Cat() {
        std::cout << "Cat destructor called." << std::endl;
    }
};

int main() {
    // Demonstrate the robustness issue with non-virtual destructor
    // When deleting via Animal* pointer, only Animal's destructor is called.
    // The derived class destructors (Dog's and Cat's) are NOT called.

    std::cout << "Creating Dog and Cat objects dynamically..." << std::endl;

    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    std::cout << "\nCalling makeSound() for myDog:" << std::endl;
    myDog->makeSound();

    std::cout << "\nCalling makeSound() for myCat:" << std::endl;
    myCat->makeSound();

    std::cout << "\nDeleting myDog via Animal* pointer (robustness issue expected):" << std::endl;
    delete myDog; // Only Animal destructor called

    std::cout << "\nDeleting myCat via Animal* pointer (robustness issue expected):" << std::endl;
    delete myCat; // Only Animal destructor called

    std::cout << "\nDemonstration complete. Notice which destructors were called." << std::endl;

    return 0;
}