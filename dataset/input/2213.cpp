#include <iostream>

class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() = default; // Good practice for base classes with virtual functions
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl; // Logical Error: Dog should make "Woof!" sound
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl; // Logical Error: Cat should make "Meow!" sound
    }
};

int main() {
    // Demonstrate that Animal cannot be instantiated directly (this would be a compile error)
    // Animal myAnimal; 

    Dog myDog;
    Cat myCat;

    Animal* animal1 = &myDog;
    Animal* animal2 = &myCat;

    std::cout << "Demonstrating sounds via Animal pointers:" << std::endl;
    animal1->makeSound(); // Expected: Woof!, Actual: Meow!
    animal2->makeSound(); // Expected: Meow!, Actual: Woof!

    return 0;
}