#include <iostream>
#include <string>
#include <vector> // Included for potential future use, not strictly needed for this example

// Animal class
class Animal {
protected:
    std::string name;
public:
    Animal(const std::string& n) : name(n) {
        // std::cout << "Animal constructor: " << name << std::endl;
    }
    // ROBUSTNESS ISSUE: Non-virtual destructor.
    // If a derived object is deleted via an Animal* pointer,
    // only this destructor will be called, leading to potential resource leaks
    // or undefined behavior for derived class specific resources.
    ~Animal() {
        std::cout << "Animal destructor: " << name << std::endl;
    }
    virtual void printDetails() const {
        std::cout << "Name: " << name;
    }
};

// Mammal class derives from Animal
class Mammal : public Animal {
protected:
    std::string furColor;
public:
    Mammal(const std::string& n, const std::string& fc)
        : Animal(n), furColor(fc) {
        // std::cout << "Mammal constructor: " << name << std::endl;
    }
    // This destructor will NOT be called if a Dog object is deleted via an Animal*
    ~Mammal() {
        std::cout << "Mammal destructor: " << name << ", Color: " << furColor << std::endl;
    }
    void printDetails() const override {
        Animal::printDetails();
        std::cout << ", Fur Color: " << furColor;
    }
};

// Dog class derives from Mammal
class Dog : public Mammal {
private:
    std::string breed;
public:
    Dog(const std::string& n, const std::string& fc, const std::string& b)
        : Mammal(n, fc), breed(b) {
        // std::cout << "Dog constructor: " << name << std::endl;
    }
    // This destructor will NOT be called if a Dog object is deleted via an Animal*
    ~Dog() {
        std::cout << "Dog destructor: " << name << ", Breed: " << breed << std::endl;
    }
    void printDetails() const override {
        Mammal::printDetails();
        std::cout << ", Breed: " << breed;
    }
};

// Driver for testing
int main() {
    // Standard usage: Object on stack, destructors called correctly upon scope exit
    Dog myDog("Buddy", "Golden", "Golden Retriever");
    myDog.printDetails();
    std::cout << std::endl;

    std::cout << "\n--- Demonstrating Robustness Issue (Non-virtual destructor) ---\n";
    // Create a Dog object dynamically and point to it with a base class pointer
    Animal* polymorphicAnimal = new Dog("Max", "Black", "Labrador");
    polymorphicAnimal->printDetails(); // Calls Dog::printDetails() correctly due to virtual function
    std::cout << std::endl;

    std::cout << "Deleting polymorphicAnimal...\n";
    // ISSUE HERE: Due to the non-virtual destructor in Animal,
    // only Animal::~Animal() is called. Mammal::~Mammal() and Dog::~Dog() are skipped.
    // This leads to undefined behavior and potential memory leaks if derived classes
    // managed their own dynamic resources.
    delete polymorphicAnimal;
    std::cout << "PolymorphicAnimal deleted. (Note: Only Animal destructor was called for Max)\n";

    return 0;
}