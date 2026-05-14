#include <iostream>
#include <vector>
#include <string> // Required for string return type

// Abstract base class
class Animal {
public:
    // Pure virtual method now returns a string instead of printing directly
    virtual std::string getSound() = 0;
    // Virtual destructor is present to avoid robustness issues, but the primary
    // issue here is efficiency/readability of the 'makeSound' implementation.
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    // Overrides to return a string, adding an extra step before printing
    std::string getSound() override {
        return "Woof! (via string return)";
    }
    ~Dog() override {}
};

class Cat : public Animal {
public:
    // Overrides to return a string, adding an extra step before printing
    std::string getSound() override {
        return "Meow! (via string return)";
    }
    ~Cat() override {}
};

// Helper function to process animals, adding an extra layer of indirection
void processAnimalsAndMakeSounds(const std::vector<Animal*>& animalList) {
    for (Animal* animal : animalList) {
        // This involves creating a string, returning it, and then printing it.
        // Less efficient than printing directly inside the Animal method.
        std::cout << animal->getSound() << std::endl;
    }
}

int main() {
    // Using raw pointers and explicit new/delete, which is less readable and
    // more error-prone than using stack objects or smart pointers like std::unique_ptr
    Animal* animalPtr1 = new Dog();
    Animal* animalPtr2 = new Cat();
    Animal* animalPtr3 = new Dog();

    std::vector<Animal*> myAnimals;
    myAnimals.push_back(animalPtr1);
    myAnimals.push_back(animalPtr2);
    myAnimals.push_back(animalPtr3);

    std::cout << "--- Animal Sounds ---" << std::endl;
    processAnimalsAndMakeSounds(myAnimals); // Using a helper function, adding indirection
    std::cout << "--- End Sounds ---" << std::endl;

    // Manual cleanup loop, which is less readable and more error-prone than smart pointers
    for (Animal* animal : myAnimals) {
        delete animal;
    }

    // An unnecessarily verbose final message
    std::cout << "All animals have successfully produced their sounds as strings and been manually deallocated from memory." << std::endl;

    return 0;
}