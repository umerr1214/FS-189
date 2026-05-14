#include <iostream>
#include <string>

// Abstract base class
class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {}
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
    // SEMANTIC ERROR: Cat does not implement the pure virtual method makeSound()
    // inherited from Animal. This makes Cat an abstract class itself,
    // even if it doesn't declare any new pure virtual functions.
public:
    void purr() {
        std::cout << "Purrr..." << std::endl;
    }
    // Missing: void makeSound() override { ... }
};

int main() {
    Dog myDog;
    myDog.makeSound();

    // This line will cause a compilation error (semantic error)
    // because 'Cat' is an abstract class (due to not implementing makeSound())
    // and therefore cannot be instantiated directly.
    // Cat myCat; // Attempting to instantiate an abstract class

    std::cout << "Attempting to instantiate Cat (which is abstract)...\n";
    // If the above line was uncommented, the program would fail to compile.
    // To demonstrate the error without preventing compilation of this file for analysis,
    // we comment out the problematic line, but the error description still applies.

    // A pointer to Cat could be declared, but not directly instantiated.
    // Cat* someCatPtr; // This is fine.

    return 0;
}