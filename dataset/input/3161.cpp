#include <iostream>
#include <string>

class Animal {
public:
    std::string name;
    void makeSound() {
        std::cout << "Generic animal sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    // Logical Error: Prints the wrong sound string
    void makeSound() {
        std::cout << "Woof Woof!" << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.name = "Buddy";
    std::cout << myDog.name << " says: ";
    myDog.makeSound();
    return 0;
}