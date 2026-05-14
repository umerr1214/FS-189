#include <iostream>
#include <string>

// Animal class
class Animal {
protected:
    std::string name;
public:
    // Constructor uses const reference to avoid unnecessary string copies, improving efficiency.
    Animal(const std::string& n) : name(n) {}

    // Virtual destructor for proper polymorphic cleanup, ensuring robustness.
    virtual ~Animal() = default;

    // Virtual printDetails for polymorphic behavior.
    virtual void printDetails() const {
        std::cout << "Name: " << name;
    }
};

// Mammal class derives from Animal
class Mammal : public Animal {
protected:
    std::string furColor;
public:
    // Constructor uses const references.
    Mammal(const std::string& n, const std::string& fc)
        : Animal(n), furColor(fc) {}

    // Override destructor, important for polymorphic classes.
    virtual ~Mammal() override = default;

    // Override printDetails, calling base class method to avoid redundancy and improve readability/maintainability.
    void printDetails() const override {
        Animal::printDetails(); // Call base class method
        std::cout << ", Fur Color: " << furColor;
    }
};

// Dog class derives from Mammal
class Dog : public Mammal {
private:
    std::string breed;
public:
    // Constructor uses const references.
    Dog(const std::string& n, const std::string& fc, const std::string& b)
        : Mammal(n, fc), breed(b) {}

    // Override destructor.
    virtual ~Dog() override = default;

    // Override printDetails, calling base class method to avoid redundancy.
    void printDetails() const override {
        Mammal::printDetails(); // Call base class method
        std::cout << ", Breed: " << breed;
    }
};

// Driver for testing
int main() {
    // Create a Dog object on the stack
    Dog myDog("Buddy", "Golden", "Golden Retriever");
    myDog.printDetails();
    std::cout << std::endl;

    std::cout << "\n--- Demonstrating Polymorphism ---\n";
    // Create a Dog object dynamically and access it via a base class pointer
    Animal* a1 = new Dog("Charlie", "White", "Poodle");
    a1->printDetails(); // Correctly calls Dog::printDetails()
    std::cout << std::endl;
    delete a1; // Correctly calls Dog, Mammal, then Animal destructors due to virtual destructors.

    return 0;
}