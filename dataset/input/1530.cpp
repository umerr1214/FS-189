#include <iostream>
#include <string>
#include <vector>

// Abstract base class
class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual function
    virtual ~Animal() {} // Virtual destructor for proper cleanup
};

// Concrete class Dog
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

// Concrete class Cat
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

// Driver code to test
void testAnimal(Animal* animal) {
    animal->makeSound();
}

int main() {
    Dog myDog;
    Cat myCat;

    testAnimal(&myDog);
    testAnimal(&myCat);

    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    // Semantic Error: Attempting to instantiate an abstract class
    // An object of an abstract class type 'Animal' cannot be created.
    Animal myAbstractAnimal; 

    a1->makeSound();
    a2->makeSound();

    delete a1;
    delete a2;

    return 0;
}