#include <iostream>
#include <string>

class Animal {
protected:
    std::string name; // Protected member
public:
    // Constructor initializes name. A default constructor is also implicitly available.
    Animal(const std::string& n = "Unnamed Animal") : name(n) {}

    // Public method to get animal name (for outside functions to indirectly access)
    std::string getAnimalNamePublic() const {
        return name;
    }
};

class Dog : public Animal {
public:
    // Dog constructor directly accesses and modifies 'name' via base class constructor
    Dog(const std::string& dogName) : Animal(dogName) {
        // 'name' is initialized by Animal's constructor
    }

    // Method to modify name directly.
    // Robustness Issue: Allows setting an empty name without validation.
    void setDogName(const std::string& newName) {
        name = newName; // Direct access to protected member
    }

    // Method to access name directly
    std::string getDogName() const {
        return name;
    }

    void bark() const {
        // Output might be awkward if name is empty
        std::cout << name << " says Woof!" << std::endl;
    }

    void displayInfo() const {
        // Output might be awkward if name is empty
        std::cout << "Dog's info: My name is " << name << "." << std::endl;
    }
};

// Outside function attempting to access 'name' directly (would cause a compile error)
// void tryAccessProtected(Animal& a) {
//     std::cout << a.name << std::endl; // ERROR: 'name' is protected
// }

int main() {
    Dog myDog("Buddy");
    myDog.bark();
    myDog.displayInfo();

    std::cout << "\nAttempting to set an empty name (Robustness Issue demonstration):" << std::endl;
    myDog.setDogName(""); // Setting an empty name, no validation
    myDog.bark(); // Output: " says Woof!" - not very robust
    myDog.displayInfo(); // Output: "Dog's info: My name is ." - awkward

    std::cout << "\nOutside function access attempt (indirect via public method):" << std::endl;
    // An outside function cannot directly access myDog.name.
    // It must use public methods provided by the class hierarchy.
    std::cout << "Dog's name via public method: " << myDog.getDogName() << std::endl;
    std::cout << "Animal's name via public method: " << myDog.getAnimalNamePublic() << std::endl;

    // Uncommenting the following lines would result in a compile-time error,
    // demonstrating that 'name' is protected and not directly accessible from outside.
    // myDog.name = "Rex";
    // std::cout << myDog.name << std::endl;

    return 0;
}