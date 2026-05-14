#include <iostream>
#include <string>
#include <vector> // Readability/Efficiency: Unnecessary include

class Animal {
protected:
    std::string name; // Protected member
public:
    Animal() {
        name = "Default Animal"; // Readability/Efficiency: Not using initializer list
    }
    Animal(std::string n) { // Readability/Efficiency: Takes string by value, causes copy
        name = n; // Readability/Efficiency: Assigns in body, not initializer list
    }
    std::string getAnimalNamePublic() { // Readability/Efficiency: Not const, returns by value (causes copy)
        return name;
    }
};

class Dog : public Animal {
public:
    Dog(std::string dogName) : Animal(dogName) { // Readability/Efficiency: Passes by value to base ctor
        // No further initialization here.
    }

    void setDogName(std::string newName) { // Readability/Efficiency: Takes string by value, causes copy
        name = newName; // Direct access to protected member
    }

    std::string getDogName() { // Readability/Efficiency: Not const, returns by value (causes copy)
        return name;
    }

    void makeSound() { // Readability: Generic name, could be more specific like 'bark' for a Dog
        std::cout << "The animal named " << name << " makes a sound." << std::endl;
        // Efficiency: Could just print "Woof!" if it's a dog, without string concatenation overhead
    }

    void printDetails() { // Readability: A bit verbose for a simple print
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Name of the dog: " << getDogName() << std::endl; // Efficiency: extra function call and copy
        std::cout << "Status: Alive" << std::endl;
        std::cout << "---------------------------------" << std::endl;
    }
};

// Outside function trying to access 'name' directly (would cause a compile error)
// void demonstrateDirectAccessFailure(Dog& d) {
//     std::cout << d.name << std::endl; // Compile error: 'name' is protected
// }

int main() {
    Dog myDog("Sparky");
    myDog.makeSound();
    myDog.printDetails();

    std::cout << "\nChanging dog's name:" << std::endl;
    std::string tempName = "Max";
    myDog.setDogName(tempName); // Efficiency: tempName copied to parameter, then assigned
    myDog.printDetails();

    std::cout << "\nDemonstrating outside function access restrictions:" << std::endl;
    // An outside function cannot directly access myDog.name.
    // It must use public methods.
    std::cout << "Dog's name (via public getter): " << myDog.getDogName() << std::endl; // Efficiency: Copy
    std::cout << "Animal's name (via public getter): " << myDog.getAnimalNamePublic() << std::endl; // Efficiency: Copy

    // The following lines would cause compile errors, demonstrating the protected nature:
    // myDog.name = "Rocky";
    // std::cout << myDog.name << std::endl;

    return 0;
}