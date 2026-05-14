#include <iostream>
#include <string>

// Abstract Base Class
class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual method
    virtual ~Animal() {} // Virtual destructor for proper cleanup
};

// Derived Dog class
class Dog : public Animal {
    // SEMANTIC ERROR: Dog does not implement makeSound(), making it an abstract class itself.
    // To fix, uncomment the following:
    // public:
    // void makeSound() override {
    //     std::cout << "Woof!" << std::endl;
    // }
};

// Derived Cat class
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // This line will cause a semantic error (compiler error)
    // trying to instantiate an abstract class 'Dog'.
    Dog myDog; // Error: cannot declare variable 'myDog' to be of abstract type 'Dog'
              // because the following virtual functions are pure within 'Dog':
              // 'virtual void Animal::makeSound()'
    
    // The rest of the code would be unreachable or also fail if myDog was used.
    // Cat myCat;
    // myCat.makeSound();

    return 0;
}