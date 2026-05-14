#include <iostream>

class Animal {
public:
    // Semantic Error: 'sound' method is not virtual.
    // This prevents polymorphic behavior when calling through base class pointers/references.
    void sound() { std::cout << "Animal makes a generic sound.\n"; }
};

class Dog : public Animal {
public:
    void sound() { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
    void sound() { std::cout << "Meow!\n"; }
};

int main() {
    Dog myDog;
    Cat myCat;

    std::cout << "Direct calls:\n";
    std::cout << "Dog sound: ";
    myDog.sound();
    std::cout << "Cat sound: ";
    myCat.sound();

    std::cout << "\nPolymorphic calls (semantic error demonstration):\n";
    Animal* polyDog = new Dog();
    Animal* polyCat = new Cat();

    std::cout << "Dog via Animal* sound: ";
    polyDog->sound(); // Calls Animal::sound() due to non-virtual base method
    std::cout << "Cat via Animal* sound: ";
    polyCat->sound(); // Calls Animal::sound() due to non-virtual base method

    delete polyDog;
    delete polyCat;

    return 0;
}