#include <iostream>
// This code demonstrates hierarchical inheritance correctly,
// but suffers from readability and minor efficiency issues.
class Animal {
public:
    // Method is virtual, allowing polymorphic behavior.
    virtual void sound() {
        std::cout << "Generic animal sound." << std::endl; // Using std::endl is less efficient than '\n'
    }
};
class Dog : public Animal {
public:
    // Overrides the sound method for Dog.
    void sound() override { // Good use of override
        std::cout << "Woof!" << std::endl; // Inconsistent indentation
    }
};
class Cat : public Animal {
public:
    // Overrides the sound method for Cat.
    void sound() override {
        // A comment that doesn't add much value.
        std::cout << "Meow!" << std::endl;
    }
};
int main() { // main function starts
    Animal *a; // Terse variable name
    Dog d; // Another terse variable name
    Cat c; // And another
    a = &d; // Assignment without clear purpose comment
    a->sound(); // Calling sound
    a = &c; // Reassigning pointer
    a->sound(); // Calling sound again
    Animal gen; // Direct object
    gen.sound(); // Calling sound directly
    return 0; // End of main
}