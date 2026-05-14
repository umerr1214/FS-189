#include <iostream>
#include <string>

class Animal {
protected:
    std::string name; // Protected member
public:
    // Constructor uses initializer list for efficiency and clarity
    Animal(const std::string& n = "Unnamed Animal") : name(n) {}

    // Public getter for indirect access, returns const reference for efficiency and const-correctness
    const std::string& getAnimalNamePublic() const {
        return name;
    }
};

class Dog : public Animal {
public:
    // Dog constructor directly accesses and modifies 'name' via base class constructor
    // Uses initializer list to call base constructor efficiently, passing by const reference
    Dog(const std::string& dogName) : Animal(dogName) {
        // 'name' is now initialized by Animal's constructor
    }

    // Method to modify name directly, takes const reference for efficiency
    void setDogName(const std::string& newName) {
        // Optional: Add validation here if desired (e.g., check for empty string)
        name = newName; // Direct access to protected member
    }

    // Method to access name directly, returns const reference for efficiency and const-correctness
    const std::string& getDogName() const {
        return name;
    }

    // Specific behavior for Dog, using getter for consistency and direct access for display
    void bark() const {
        std::cout << getDogName() << " says Woof! Woof!" << std::endl;
    }

    void displayInfo() const {
        std::cout << "Dog's details: Name is '" << name << "'." << std::endl; // Direct access for display
    }
};

// Outside function attempting to access 'name' directly (would cause a compile error)
// void attemptDirectAccess(const Dog& d) {
//     std::cout << d.name << std::endl; // This line would cause a compile error: 'name' is protected
// }

int main() {
    Dog myDog("Buddy");
    myDog.bark();
    myDog.displayInfo();

    std::cout << "\nChanging dog's name (Dog accessing protected 'name'):" << std::endl;
    myDog.setDogName("Rex");
    myDog.bark();
    myDog.displayInfo();

    std::cout << "\nDemonstrating outside function access restrictions:" << std::endl;
    // An outside function cannot directly access myDog.name.
    // It must use public methods provided by the class.
    std::cout << "Accessing Dog's name via public getter: " << myDog.getDogName() << std::endl;
    std::cout << "Accessing Animal's name via public getter: " << myDog.getAnimalNamePublic() << std::endl;

    // Uncommenting the following lines would result in a compile-time error,
    // demonstrating that 'name' is protected and not directly accessible from outside.
    // myDog.name = "Fido";
    // std::cout << myDog.name << std::endl;

    return 0;
}