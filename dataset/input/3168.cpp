#include <iostream>
#include <string>

class Animal {
public: // Semantic Error: 'name' should be protected, not public.
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    void displayAnimalName() const {
        std::cout << "Animal name: " << name << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}

    void changeName(const std::string& newName) {
        this->name = newName; // Dog can access 'name' directly (it's public here)
        std::cout << "Dog changed name to: " << this->name << std::endl;
    }
};

// An outside function attempting to access name directly
void outsideFunction(Animal& animal) {
    // This line should NOT be allowed if 'name' was protected, but it IS allowed here
    // because 'name' is erroneously declared as public. This demonstrates the semantic error.
    animal.name = "OutsideName";
    std::cout << "Outside function modified name directly to: " << animal.name << std::endl;
}

int main() {
    Dog myDog("Buddy");
    myDog.displayAnimalName(); // Initial name

    myDog.changeName("Rex"); // Dog changes name
    myDog.displayAnimalName(); // Display name after Dog's modification

    outsideFunction(myDog); // Outside function modifies name directly
    myDog.displayAnimalName(); // Display name after outside function's modification

    return 0;
}