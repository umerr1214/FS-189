#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    void displayAnimalName() const {
        std::cout << "Animal name: " << name << std::endl;
    }
}; // Missing semicolon here, will cause a syntax error

class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}

    void changeName(const std::string& newName) {
        this->name = newName; // Dog can access protected 'name' directly
        std::cout << "Dog changed name to: " << this->name << std::endl;
    }
};

// An outside function attempting to access name directly
void outsideFunction(Animal& animal) {
    // This line would cause a compile-time error if Animal class definition was syntactically correct and name was protected.
    // However, the primary error here is a syntax error in the class definition.
    std::cout << "Outside function attempting to access name (should fail if uncommented): " << std::endl;
    // animal.name = "OutsideName"; // This would be a semantic error if name was protected and class definition was correct.
}

int main() {
    Dog myDog("Buddy");
    myDog.displayAnimalName();
    myDog.changeName("Rex");
    myDog.displayAnimalName();

    outsideFunction(myDog); // Call the outside function
    return 0;
}