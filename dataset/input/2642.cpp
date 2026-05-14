#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr

class Animal {
private:
    std::string species;

public:
    // Efficiency issue: Passing std::string by value creates an unnecessary copy
    Animal(std::string s) : species(s) {
    }

    // Virtual for proper polymorphism (correctness maintained here)
    virtual void makeSound() const {
        std::cout << "Animal makes a sound. Species: " << species << std::endl;
    }

protected:
    const std::string& getSpecies() const { return species; }
};

class Dog : public Animal {
private:
    std::string name;

public:
    // Efficiency issue: Passing std::string by value creates unnecessary copies for both parameters
    // Readability/Efficiency issue: 'name' is initialized in the constructor body via assignment,
    // which is less efficient than using a member initializer list (it involves default construction
    // followed by assignment).
    Dog(std::string species_val, std::string name_val)
        : Animal(species_val) { // Base constructor called correctly
        this->name = name_val; // Inefficient assignment instead of initializer list
    }

    void makeSound() const override {
        // Readability/Efficiency issue: Using multiple '+' for string concatenation can be less efficient
        // than direct stream insertion or using stringstream for complex formatting.
        std::cout << "Woof! My name is " + name + ". Species: " + getSpecies() + "." << std::endl;
    }
};

int main() {
    // Create an Animal object
    Animal genericAnimal("Cat");
    genericAnimal.makeSound();

    // Create a Dog object
    Dog myDog("Poodle", "Lucy");
    myDog.makeSound();

    // Demonstrate polymorphism (this part is correct, the issues are in constructors/makeSound implementations)
    std::unique_ptr<Animal> polyAnimal = std::make_unique<Dog>("German Shepherd", "Rex");
    polyAnimal->makeSound();
    
    std::unique_ptr<Animal> anotherAnimal = std::make_unique<Animal>("Snake");
    anotherAnimal->makeSound();

    return 0;
}