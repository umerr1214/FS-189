#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr

// Base class
class Animal {
private:
    std::string species_; // Private member

public:
    // Constructor
    Animal(const std::string& s) : species_(s) {
        std::cout << "Animal constructor called for " << species_ << std::endl;
    }

    // Virtual destructor for proper polymorphic cleanup
    virtual ~Animal() {
        std::cout << "Animal destructor called for " << species_ << std::endl;
    }

    // Public getter method
    std::string getSpecies() const {
        return species_;
    }

    // Unique characteristic (method) at this level
    virtual void eat() const { // Virtual for potential overriding
        std::cout << species_ << " is eating." << std::endl;
    }
};

// Derived class 1
class Mammal : public Animal {
private:
    std::string furColor_; // Private member

public:
    // Constructor
    Mammal(const std::string& s, const std::string& fc)
        : Animal(s), furColor_(fc) {
        std::cout << "Mammal constructor called for " << getSpecies() << " with " << furColor_ << " fur." << std::endl;
    }

    // Destructor (implicitly virtual)
    ~Mammal() override {
        std::cout << "Mammal destructor called for " << getSpecies() << std::endl;
    }

    // Public getter method
    std::string getFurColor() const {
        return furColor_;
    }

    // Unique characteristic (method) at this level
    void giveBirth() const {
        std::cout << getSpecies() << " (a mammal) is giving birth to live young." << std::endl;
    }

    // Override base class method (optional but good practice)
    void eat() const override {
        std::cout << getSpecies() << " is eating mammal food." << std::endl;
    }
};

// Derived class 2
class Dog : public Mammal {
private:
    std::string breed_; // Private member

public:
    // Constructor
    Dog(const std::string& s, const std::string& fc, const std::string& b)
        : Mammal(s, fc), breed_(b) {
        std::cout << "Dog constructor called for " << getSpecies() << " of breed " << breed_ << "." << std::endl;
    }

    // Destructor (implicitly virtual)
    ~Dog() override {
        std::cout << "Dog destructor called for " << getSpecies() << " (breed: " << breed_ << ")." << std::endl;
    }

    // Public getter method
    std::string getBreed() const {
        return breed_;
    }

    // Unique characteristic (method) at this level
    void bark() const {
        std::cout << getSpecies() << " (" << breed_ << ") barks: Woof! Woof!" << std::endl;
    }

    // Override base class method
    void eat() const override {
        std::cout << getSpecies() << " (" << breed_ << ") is enthusiastically eating dog kibble." << std::endl;
    }
};

void run_demonstration() {
    std::cout << "--- Demonstrating multi-level inheritance with a Dog object ---" << std::endl;

    // Create a Dog object
    Dog myDog("Canine", "Golden", "Golden Retriever");

    // Access characteristics and call methods from all levels
    std::cout << "\nDog Details:" << std::endl;
    std::cout << "Species: " << myDog.getSpecies() << std::endl; // From Animal
    std::cout << "Fur Color: " << myDog.getFurColor() << std::endl; // From Mammal
    std::cout << "Breed: " << myDog.getBreed() << std::endl; // From Dog

    myDog.eat(); // Overridden method, calls Dog's eat()
    myDog.giveBirth(); // From Mammal
    myDog.bark(); // From Dog
    std::cout << std::endl;

    std::cout << "--- Demonstrating polymorphic behavior with smart pointers ---" << std::endl;
    std::unique_ptr<Animal> animalPtr = std::make_unique<Dog>("Canine", "Black", "Labrador");
    std::cout << "Polymorphic Animal (Dog) Species: " << animalPtr->getSpecies() << std::endl;
    animalPtr->eat(); // Calls Dog's overridden eat() due to virtual function
    // Cannot directly call giveBirth() or bark() through Animal* without dynamic_cast
    std::cout << "Smart pointer will handle deletion automatically, calling virtual destructors." << std::endl;
    // When animalPtr goes out of scope, it will correctly call Dog, Mammal, then Animal destructors
    std::cout << std::endl;

    std::cout << "--- Demonstration finished. Objects will be destructed. ---" << std::endl;
}

int main() {
    run_demonstration();
    return 0;
}