#include <iostream>
#include <string> // Not strictly needed for this version, but good practice if more complex strings were used

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
    // Create a fixed-size C-style array of Animal pointers
    const int MAX_ANIMALS = 5; // A fixed size, possibly larger than needed
    Animal* animals[MAX_ANIMALS];
    int actual_animal_count = 0;

    // Populate the array with Dog and Cat objects using manual indexing
    animals[actual_animal_count++] = new Dog();
    animals[actual_animal_count++] = new Cat();
    animals[actual_animal_count++] = new Dog();
    // We could add more up to MAX_ANIMALS, but will stop here for this example.

    std::cout << "--- Demonstrating Polymorphism ---" << std::endl;
    // Iterate through the array using a traditional for loop with an index
    for (int i = 0; i < actual_animal_count; ++i) {
        std::cout << "Animal " << (i + 1) << ": ";
        animals[i]->makeSound();
    }
    std::cout << "---------------------------------" << std::endl;

    // Clean up dynamically allocated memory using a traditional for loop
    for (int i = 0; i < actual_animal_count; ++i) {
        delete animals[i];
    }

    std::cout << "\nExplanation of Output:" << std::endl;
    std::cout << "When makeSound() is called, the correct overridden version (from Dog or Cat) is executed." << std::endl;
    std::cout << "This is due to polymorphism: the makeSound() method in Animal is virtual, allowing dynamic dispatch." << std::endl;
    std::cout << "The program correctly calls the Dog's makeSound for Dog objects and Cat's makeSound for Cat objects, even though they are accessed via 'Animal*' pointers." << std::endl;
    std::cout << "Unlike the previous example, observe that both derived and base class destructors are called ('Dog destructor called.', 'Cat destructor called.', then 'Animal destructor called.'). This is because the Animal base class now has a virtual destructor, ensuring proper memory cleanup." << std::endl;
    std::cout << "The code is functional, but uses C-style arrays and manual pointer management, which can be less safe and less readable than modern C++ alternatives like std::vector and smart pointers." << std::endl;

    return 0;
}