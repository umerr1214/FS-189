#include <iostream>

class Animal {
public:
    // Semantic Error: makeSound is not pure virtual.
    // This makes Animal a concrete class, allowing it to be instantiated directly,
    // which violates the problem statement's requirement for an abstract base class.
    virtual void makeSound() {
        std::cout << "Generic animal sound." << std::endl;
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // This instantiation is now allowed, which violates the problem's intent
    // that Animal should be an abstract base class that cannot be instantiated directly.
    Animal myAnimal; // Semantic error relative to the problem description
    std::cout << "Instantiating Animal directly (violates problem requirement):" << std::endl;
    myAnimal.makeSound();

    Dog myDog;
    Cat myCat;

    Animal* animal1 = &myDog;
    Animal* animal2 = &myCat;

    std::cout << "\nDemonstrating sounds via Animal pointers:" << std::endl;
    animal1->makeSound();
    animal2->makeSound();

    return 0;
}