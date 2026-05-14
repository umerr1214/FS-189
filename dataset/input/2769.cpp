#include <iostream>
#include <vector>
#include <string>
#include <memory> // For std::unique_ptr

// Base class Animal
class Animal {
public:
    std::string name;
    Animal(const std::string& n) : name(n) {}

    // Virtual function for sound, pure virtual makes Animal an abstract class
    virtual void sound() const = 0;

    // Essential virtual destructor for proper polymorphic cleanup
    virtual ~Animal() {
        std::cout << "Animal " << name << " destroyed.\n";
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}
    void sound() const override {
        std::cout << name << " barks: Woof! Woof!" << std::endl;
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
        std::cout << name << " meows: Meow!" << std::endl;
    }
    ~Cat() override {
        std::cout << name << " (Cat) destroyed.\n";
    }
};

// Zoo class to showcase polymorphic behavior with modern C++ practices
class Zoo {
private:
    // Using std::unique_ptr for proper ownership and automatic memory management
    std::vector<std::unique_ptr<Animal>> animals;

public:
    Zoo() {
        std::cout << "Zoo is open for business!" << std::endl;
    }

    // Takes ownership of a unique_ptr to an Animal
    void addAnimal(std::unique_ptr<Animal> animal) {
        if (animal == nullptr) {
            std::cerr << "Warning: Attempted to add a null animal.\n";
            return;
        }
        std::cout << "Adding " << animal->name << " to the zoo.\n";
        animals.push_back(std::move(animal)); // Move ownership into the vector
    }

    // Calls the sound method on all animals, demonstrating polymorphism
    void makeAllSounds() const {
        std::cout << "\n--- All animals in the zoo are making sounds! ---\n";
        for (const auto& animal_ptr : animals) {
            animal_ptr->sound();
        }
        std::cout << "--- End of animal sounds ---\n";
    }

    // Destructor will automatically clean up unique_ptr objects
    ~Zoo() {
        std::cout << "Zoo is closing. All animals will be automatically destroyed.\n";
        // std::vector<std::unique_ptr<Animal>> automatically calls destructors
        // for its elements when the vector itself is destroyed.
    }
};

int main() {
    Zoo myZoo;

    // Create unique_ptr objects for different animal types
    // std::make_unique is preferred for safety and efficiency
    auto dog = std::make_unique<Dog>("Max");
    auto cat = std::make_unique<Cat>("Luna");
    auto anotherDog = std::make_unique<Dog>("Charlie");

    // Add animals to the zoo, transferring ownership
    myZoo.addAnimal(std::move(dog));
    myZoo.addAnimal(std::move(cat));
    myZoo.addAnimal(std::move(anotherDog));

    // Demonstrate polymorphic behavior
    myZoo.makeAllSounds();

    // No explicit 'delete' calls needed thanks to std::unique_ptr
    std::cout << "\nProgram ending. Unique pointers will clean up automatically.\n";

    return 0;
}