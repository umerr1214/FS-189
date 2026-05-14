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
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl // SYNTAX ERROR: Missing semicolon here
    }
};

int main() {
    // The program will fail to compile due to the syntax error in Cat class
    // before reaching this point.
    Dog myDog;
    // Cat myCat; // This line would cause a compilation error due to the syntax issue above.

    myDog.makeSound();
    // myCat.makeSound();

    return 0;
}