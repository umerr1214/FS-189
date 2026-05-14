#include <iostream>
#include <vector>
#include <string>

// Base class Animal (from Q14 context)
class Animal {
public:
    std::string name;
    Animal(const std::string& n) : name(n) {}

    // Virtual function for sound - missing virtual destructor is the robustness issue
    virtual void sound() const {
        std::cout << name << " makes a generic animal sound." << std::endl;
    }
    // Robustness Issue: Missing 'virtual' destructor.
    // If a derived object is deleted via an Animal* pointer,
    // the derived class's destructor will not be called, leading to resource leaks.
    // ~Animal() { std::cout << name << " destructor called." << std::endl; }
};

// Derived class Dog
class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}
    void sound() const override {
        std::cout << name << " barks: Woof! Woof!" << std::endl;
    }
    ~Dog() { std::cout << name << " (Dog) destructor called." << std::endl; }
};

// Derived class Cat
class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}
    void sound() const override {
        std::cout << name << " meows: Meow!" << std::endl;
    }
    ~Cat() { std::cout << name << " (Cat) destructor called." << std::endl; }
};

// Zoo class to showcase polymorphic behavior
class Zoo {
public:
    // This method takes an Animal pointer and calls its sound method.
    // Robustness Issue: Does not check for nullptr before dereferencing.
    void hostAnimalAndMakeSound(Animal* animal) const {
        // If 'animal' is nullptr, this will cause a runtime crash (dereferencing null).
        // A robust solution would check: if (animal != nullptr) { ... }
        std::cout << "The zoo hosts " << animal->name << " and it says: ";
        animal->sound();
    }
};

int main() {
    Zoo myZoo;

    // Demonstrate normal polymorphic behavior
    Dog* myDog = new Dog("Buddy");
    Cat* myCat = new Cat("Whiskers");

    myZoo.hostAnimalAndMakeSound(myDog);
    myZoo.hostAnimalAndMakeSound(myCat);

    std::cout << "\n--- Demonstrating robustness issues ---\n";

    // Issue 1: Missing virtual destructor
    // Deleting via base pointer without virtual destructor.
    // The Dog destructor will NOT be called, leading to a memory leak for Dog-specific resources.
    // Only Animal's destructor (if it had one) would be called.
    // In this specific code, since Animal has no explicit destructor, it's less obvious,
    // but if Animal had resources, they wouldn't be cleaned up for the derived part.
    // The Dog destructor message will not appear for 'Buddy'.
    Animal* genericAnimalPtr = new Dog("LeakDog");
    std::cout << "Attempting to delete 'LeakDog' via Animal* (watch for Dog destructor message):\n";
    delete genericAnimalPtr; // Dog::~Dog() is NOT called if Animal::~Animal() is not virtual
    std::cout << "If you didn't see 'LeakDog (Dog) destructor called.', it's a leak.\n";


    // Issue 2: Dereferencing nullptr in hostAnimalAndMakeSound
    std::cout << "\nAttempting to host a nullptr animal (EXPECT CRASH or undefined behavior):\n";
    // This line will cause a segmentation fault or similar crash because
    // hostAnimalAndMakeSound doesn't check for null.
    // Comment out the line below to avoid crashing the program if running directly.
    // myZoo.hostAnimalAndMakeSound(nullptr);

    // Clean up normally allocated objects
    delete myDog; // Dog destructor for Buddy WILL be called
    delete myCat; // Cat destructor for Whiskers WILL be called

    return 0;
}