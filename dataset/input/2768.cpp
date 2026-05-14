#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::for_each

// Base class Animal
class Animal {
public:
    std::string name;
    Animal(const std::string& n) : name(n) {
        std::cout << "Animal " << name << " created.\n";
    }
    virtual void sound() const {
        std::cout << name << " makes a generic animal sound (default implementation)." << std::endl;
    }
    // Essential virtual destructor for proper cleanup
    virtual ~Animal() {
        std::cout << "Animal " << name << " destroyed.\n";
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}
    void sound() const override {
        std::cout << name << " barks: Woof! Woof! (Very loudly, much wow!)" << std::endl;
    }
    ~Dog() override {
        std::cout << name << " (Dog) destroyed.\n";
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}
    void sound() const override {
        std::cout << name << " meows: Meow! (Purrrfectly adorable.)" << std::endl;
    }
    ~Cat() override {
        std::cout << name << " (Cat) destroyed.\n";
    }
};

// Zoo class showcasing Readability/Efficiency Issue
class Zoo {
private:
    // Readability/Efficiency Issue: Using raw pointers in a vector requires manual memory management
    // from the user of the Zoo class. This is error-prone and less efficient than smart pointers.
    std::vector<Animal*> animals_in_zoo_list; // Poor naming convention, verbose

public:
    Zoo() {
        std::cout << "Zoo is open for business!" << std::endl;
    }

    // Readability/Efficiency Issue: Transfers ownership to the vector, but the user
    // still needs to manually delete the pointers after the zoo is done with them.
    // This is not clear from the signature alone and leads to potential leaks or double-frees.
    void addAnimalToCollection(Animal* theAnimalPointer) {
        if (theAnimalPointer == nullptr) { // Basic null check is present
            std::cerr << "Warning: Attempted to add a null animal pointer.\n";
            return;
        }
        animals_in_zoo_list.push_back(theAnimalPointer);
        std::cout << "Added " << theAnimalPointer->name << " to the zoo's collection. Remember to delete it later!\n";
    }

    // This method is functional but the management of animals_in_zoo_list is inefficient
    void makeAllZooAnimalsSoundOff() const {
        std::cout << "\n--- All animals in the zoo are making sounds! ---\n";
        // Using a range-based for loop, which is readable.
        // The issue is not in this loop itself, but the underlying data structure choice.
        for (const auto& individual_animal_entry : animals_in_zoo_list) {
            individual_animal_entry->sound();
        }
        std::cout << "--- End of animal sounds ---\n";
    }

    // Readability/Efficiency Issue: The destructor does NOT delete the animals,
    // placing the burden on the caller. This is an implicit contract that is easy to break.
    // A more efficient/safer design would use smart pointers or clear ownership.
    ~Zoo() {
        std::cout << "Zoo is closing. Remember to manually delete all animals you added!\n";
        // If the zoo *owned* the animals, it would delete them here.
        // But in this design, it merely holds pointers.
    }
};

int main() {
    Zoo my_local_zoo_instance; // Verbose variable name

    // Creating animals using raw pointers
    Dog* doggo = new Dog("Fido");
    Cat* kitty = new Cat("Mittens");
    Animal* generic_animal = new Animal("Blob"); // Can also add a base Animal

    my_local_zoo_instance.addAnimalToCollection(doggo);
    my_local_zoo_instance.addAnimalToCollection(kitty);
    my_local_zoo_instance.addAnimalToCollection(generic_animal);

    my_local_zoo_instance.makeAllZooAnimalsSoundOff();

    std::cout << "\n--- Manual cleanup phase ---\n";
    // Readability/Efficiency Issue: Manual deletion is required,
    // which is prone to errors (forgetting to delete, double deletion).
    delete doggo;
    delete kitty;
    delete generic_animal;

    std::cout << "All animals manually deleted. Program ending.\n";

    return 0;
}