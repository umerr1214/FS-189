#include <iostream>
#include <string>

class Animal {
public:
    std::string name;
    void makeSound() {
        std::cout << "Generic animal sound." << std::endl;
    }
} // Syntax Error: Missing semicolon here

class Dog : public Animal {
public:
    void makeSound() {
        std::cout << "Woof!" << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.name = "Buddy";
    std::cout << myDog.name << " says: ";
    myDog.makeSound();
    return 0;
}