#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
public:
    Animal(const std::string& n) : name(n) {}
    virtual void printDetails() const {
        std::cout << "Name: " << name;
    }
};

class Mammal : public Animal // Syntax Error: Missing semicolon after class definition
{
protected:
    std::string furColor;
public:
    Mammal(const std::string& n, const std::string& fc)
        : Animal(n), furColor(fc) {}
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