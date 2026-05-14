#include <iostream>
#include <string>

// Animal class
class Animal {
protected:
std::string name;
public:
Animal(std::string n) : name(n) { // EFFICIENCY ISSUE: Passing std::string by value causes an unnecessary copy
// std::cout << "Animal constructed: " << name << std::endl;
}
virtual ~Animal() = default;
virtual void printDetails() const {
std::cout << "Name: " << name;
}
};

// Mammal class derives from Animal
class Mammal : public Animal {
protected:
std::string furColor;
public:
Mammal(std::string n, std::string fc) // EFFICIENCY ISSUE: Passing std::string by value causes unnecessary copies
: Animal(n), furColor(fc) {
// std::cout << "Mammal constructed: " << name << std::endl;
}
virtual ~Mammal() override = default;
void printDetails() const override { // READABILITY/EFFICIENCY ISSUE: Redundant code. Re-implements Animal's logic.
std::string animal_name_local_copy = this->name; // Unnecessary temporary variable
std::cout << "Name: " << animal_name_local_copy << ", Fur Color: " << furColor;
}
};

// Dog class derives from Mammal
class Dog : public Mammal {
private:
std::string breed;
public:
Dog(std::string n, std::string fc, std::string b) // EFFICIENCY ISSUE: Passing std::string by value causes unnecessary copies
: Mammal(n, fc), breed(b) {
// std::cout << "Dog constructed: " << name << std::endl;
}
virtual ~Dog() override = default;
void printDetails() const override { // READABILITY/EFFICIENCY ISSUE: Redundant code. Re-implements Mammal's (and thus Animal's) logic.
// Instead of calling Mammal::printDetails(), it copies the logic, making it less maintainable.
std::string dog_name_temp = this->name; // Another unnecessary temporary
std::string dog_fur_color_temp = this->furColor; // Another unnecessary temporary
std::cout << "Name: " << dog_name_temp << ", Fur Color: " << dog_fur_color_temp << ", Breed: " << breed;
}
};

// Driver for testing
int main() {
Dog myDog("Sparky", "Brown", "Poodle");
myDog.printDetails();
std::cout << std::endl;
return 0;
}