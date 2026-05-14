#include <iostream>
#include <string>

class Animal {
private:
    std::string name;
public:
    Animal(const std::string& n) : name(n) {}
    // No default constructor defined for Animal
    virtual void printDetails() const {
        std::cout << "Name: " << name;
    }
};

class Mammal : public Animal {
protected:
    std::string furColor;
public:
    // Semantic Error: Mammal constructor fails to explicitly call Animal's constructor.
    // Since Animal has no default constructor, this will result in a compilation error.
    Mammal(const std::string& n, const std::string& fc)
        : furColor(fc) {} // Only initializes furColor, but not the Animal base part
    void printDetails() const override {
        Animal::printDetails();
        std::cout << ", Fur Color: " << furColor;
    }
};

class Dog : public Mammal {
private:
    std::string breed;
public:
    Dog(const std::string& n, const std::string& fc, const std::string& b)
        : Mammal(n, fc), breed(b) {}
    void printDetails() const override {
        Mammal::printDetails();
        std::cout << ", Breed: " << breed << std::endl;
    }
};

int main() {
    Dog myDog("Buddy", "Golden", "Golden Retriever");
    myDog.printDetails();

    Mammal myMammal("Whiskers", "Tabby");
    myMammal.printDetails();
    std::cout << std::endl;
    
    Animal genericAnimal("Leo");
    genericAnimal.printDetails();
    std::cout << std::endl;

    return 0;
}