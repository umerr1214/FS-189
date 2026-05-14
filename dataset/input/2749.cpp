#include <iostream> // Required for input/output operations

// Base class Animal
class Animal {
public:
    // The 'sound' method is NOT declared virtual.
    // This is the robustness issue: it prevents polymorphic behavior
    // when calling sound() through a base class pointer or reference.
    void sound() {
        std::cout << "Generic animal sound." << std::endl;
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    // This method hides Animal::sound() when called directly on a Dog object,
    // but will not be called polymorphically through an Animal pointer if Animal::sound() is not virtual.
    void sound() {
        std::cout << "Woof!" << std::endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    // Similar to Dog, this method hides Animal::sound().
    void sound() {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // Create direct objects of derived and base classes
    Dog myDog;
    Cat myCat;
    Animal genericAnimal;

    std::cout << "--- Direct object calls (work as expected) ---\n";
    myDog.sound();          // Calls Dog::sound()
    myCat.sound();          // Calls Cat::sound()
    genericAnimal.sound();  // Calls Animal::sound()
    std::cout << '\n';

    // Demonstrate the robustness issue:
    // Using base class pointers to derived objects without a virtual function.
    Animal* animalPtrDog = &myDog;
    Animal* animalPtrCat = &myCat;
    Animal* animalPtrGeneric = &genericAnimal;

    std::cout << "--- Polymorphic calls (Robustness Issue: Missing 'virtual') ---\n";
    // Due to Animal::sound() not being virtual, these calls will invoke Animal::sound()
    // instead of the derived class's sound() method, leading to incorrect behavior.
    animalPtrDog->sound();     // Expected: Woof!, Actual (bug): Generic animal sound.
    animalPtrCat->sound();     // Expected: Meow!, Actual (bug): Generic animal sound.
    animalPtrGeneric->sound(); // Expected: Generic animal sound., Actual: Generic animal sound.

    return 0;
}