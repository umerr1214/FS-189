#include <iostream>
#include <string>

// Abstract base class
class Animal {
public:
    // Pure virtual method
    virtual void makeSound() = 0;
    virtual ~Animal() {}
};

// Derived class Dog - correctly overrides makeSound
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

// Derived class Cat - fails to override makeSound, making it abstract
class Cat : public Animal {
    // Semantic Error: makeSound() is not overridden, so Cat remains an abstract class.
    // An attempt to instantiate Cat directly will result in a compilation error.
};

int main() {
    Animal* myDog = new Dog();
    myDog->makeSound();

    // Semantic Error: Cannot instantiate abstract class 'Cat'
    // This line will cause a compilation error because Cat does not override makeSound()
    // Cat myCat; 
    // myCat.makeSound();

    // Animal* myAbstractCat = new Cat(); // This would also cause a compilation error

    delete myDog;
    // delete myAbstractCat; // If it were allowed

    return 0;
}