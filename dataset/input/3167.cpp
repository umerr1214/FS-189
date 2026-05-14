#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    // Logical Error: This method does not print the actual 'name' member.
    // It prints a generic message instead of the current value of 'name'.
    void displayAnimalName() const {
        std::cout << "Animal's current name: [Placeholder Name]" << std::endl; // Logical error here
    }

    const std::string& getName() const {
        return name;
    }
};

class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}

    void changeName(const std::string& newName) {
        this->name = newName; // Dog can access protected 'name' directly
        std::cout << "Dog changed name to: " << this->name << std::endl;
    }
};

// An outside function attempting to access name directly
void outsideFunctionAttempt(Animal& animal) {
    std::cout << "Outside function attempting to access name: Blocked (would cause compile error if uncommented)" << std::endl;
    // animal.name = "OutsideName"; // This line would cause a compile-time error
    // animal.getName(); // This is allowed as getName() is public
}

int main() {
    Dog myDog("Buddy");
    myDog.displayAnimalName(); // Expected: "Animal name: Buddy", Actual: "Animal's current name: [Placeholder Name]"
    myDog.changeName("Rex");
    myDog.displayAnimalName(); // Expected: "Animal name: Rex", Actual: "Animal's current name: [Placeholder Name]"

    outsideFunctionAttempt(myDog); // Demonstrate outside function cannot access protected member
    return 0;
}