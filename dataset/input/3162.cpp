#include <iostream>
#include <string>

class Animal {
public:
    std::string name;
    void makeSound() {
        std::cout << "Generic animal sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    // Semantic Error: This overloads, rather than overrides, makeSound
    // because it has a different signature. It hides Animal::makeSound().
    void makeSound(int volume) { // Added an int parameter
        std::cout << "Woof! (volume: " << volume << ")" << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.name = "Buddy";
    std::cout << myDog.name << " says: ";
    // This line will cause a compile error because Dog::makeSound() with no arguments
    // is hidden by Dog::makeSound(int volume) and no such function exists.
    myDog.makeSound(); 
    return 0;
}