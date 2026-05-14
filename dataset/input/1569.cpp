#include <iostream>
#include <vector>
#include <memory> // Required for std::unique_ptr

// Base Animal class (from Question 11, adapted for this problem)
class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
    // Correct virtual destructor to ensure proper cleanup of derived objects
    virtual ~Animal() {
        std::cout << "Animal destructor called." << std::endl;
    }
};

// Derived Dog class
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
    ~Dog() {
        std::cout << "Dog destructor called." << std::endl;
    }
};

// Derived Cat class
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
    ~Cat() {
        std::cout << "Cat destructor called." << std::endl;
    }
};

int main() {
    // Create a vector of unique_ptr to Animal objects.
    // std::unique_ptr ensures automatic memory management and proper cleanup.
    std::vector<std::unique_ptr<Animal>> animals;

    // Populate the vector with Dog and Cat objects using std::make_unique
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    std::cout << "--- Demonstrating Polymorphism ---" << std::endl;
    // Iterate through the vector using a range-based for loop and call makeSound()
    int animal_count = 1;
    for (const auto& animal_ptr : animals) {
        std::cout << "Animal " << animal_count++ << ": ";
        animal_ptr->makeSound(); // Call virtual function
    }
    std::cout << "---------------------------------" << std::endl;

    // Memory cleanup is automatically handled by std::unique_ptr when 'animals' goes out of scope.
    // The virtual destructor in Animal ensures that derived destructors are called correctly.

    std::cout << "\nExplanation of Output:" << std::endl;
    std::cout << "The output clearly demonstrates polymorphism. When makeSound() is called on 'Animal*' (specifically, 'std::unique_ptr<Animal>'), the program correctly invokes the overridden method specific to the actual object type (Dog or Cat) at runtime." << std::endl;
    std::cout << "This dynamic dispatch is enabled by declaring makeSound() as 'virtual' in the base Animal class." << std::endl;
    std::cout << "Furthermore, observe the destructor calls: 'Dog destructor called.', 'Cat destructor called.', followed by 'Animal destructor called.' for each object." << std::endl;
    std::cout << "This confirms that the virtual destructor in the Animal base class, combined with std::unique_ptr, ensures proper and complete memory deallocation for both derived and base class parts of the objects, preventing memory leaks." << std::endl;
    std::cout << "Using std::vector and std::unique_ptr provides robust, safe, and readable memory management compared to raw pointers and manual 'new'/'delete'." << std::endl;

    return 0;
}