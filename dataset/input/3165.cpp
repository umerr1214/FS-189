#include <iostream>
#include <string>

// Base class Animal
class Animal {
public:
    std::string name;

    // Efficient: Constructor takes string by const reference
    Animal(const std::string& n) : name(n) {
        // Constructor uses initializer list for direct initialization
    }

    // Base class makeSound method
    void makeSound() {
        std::cout << "Animal " << name << " says: Generic animal sound." << std::endl;
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    // Efficient: Constructor takes string by const reference and passes to base
    Dog(const std::string& n) : Animal(n) {
        // Base class constructor handles name initialization
    }

    // Overrides makeSound without using virtual (static dispatch)
    void makeSound() {
        std::cout << "Dog " << name << " says: Woof!" << std::endl;
    }
};

int main() {
    // Create an Animal object
    Animal genericAnimal("Generic");
    genericAnimal.makeSound();

    // Create a Dog object
    Dog myDog("Buddy");
    myDog.makeSound();

    // Note: Without 'virtual' keyword, polymorphism via base class pointers/references
    // would not call the derived class's makeSound. The question explicitly states
    // 'without using virtual functions', so this direct usage is correct for the prompt.

    return 0;
}