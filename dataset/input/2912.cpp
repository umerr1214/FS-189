#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Used for string building, potentially less efficient for simple cases

// Abstract base class Animal
class Animal {
public:
    // Pure virtual method
    virtual void makeSound() = 0;
    virtual ~Animal() = default; // Good practice, but not the focus of this issue
};

// Concrete class Dog
class Dog : public Animal {
public:
    void makeSound() override {
        // Inefficient string building for a simple output
        std::stringstream ss;
        ss << "Woof";
        ss << "! ";
        ss << "Woof!";
        std::cout << ss.str() << std::endl;
    }
};

// Concrete class Cat
class Cat : public Animal {
public:
    void makeSound() override {
        // Multiple separate std::cout calls, slightly less efficient than one
        std::cout << "Meow";
        std::cout << "!";
        std::cout << " Purr.";
        std::cout << std::endl;
    }
};

// A factory-like function that's overly verbose and uses raw pointers
Animal* createAnimal(const std::string& type) {
    if (type == "dog") {
        return new Dog(); // Raw pointer allocation
    } else if (type == "cat") {
        return new Cat(); // Raw pointer allocation
    } else {
        std::cout << "Unknown animal type: " << type << std::endl;
        return nullptr;
    }
}

int main() {
    // Using the verbose factory and raw pointers, requiring manual deletion
    std::vector<Animal*> zoo;

    Animal* animal1 = createAnimal("dog");
    if (animal1) {
        zoo.push_back(animal1);
    }

    Animal* animal2 = createAnimal("cat");
    if (animal2) {
        zoo.push_back(animal2);
    }

    Animal* animal3 = createAnimal("dog"); // Creating another dog
    if (animal3) {
        zoo.push_back(animal3);
    }

    for (Animal* animal : zoo) {
        animal->makeSound();
    }

    // Manual cleanup of raw pointers - prone to errors
    for (Animal* animal : zoo) {
        delete animal;
    }
    zoo.clear(); // Clear the vector after deleting pointers

    // Demonstrating direct creation for a simple case
    Dog directDog;
    Cat directCat;
    directDog.makeSound();
    directCat.makeSound();

    return 0;
}