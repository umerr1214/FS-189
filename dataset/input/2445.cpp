#include <iostream>
#include <memory> // For std::unique_ptr

// Abstract base class Animal
class Animal {
public:
    // Pure virtual method, must be implemented by derived classes
    virtual void makeSound() const = 0;

    // Virtual destructor: Essential for proper cleanup in polymorphic hierarchies.
    // Ensures that the correct derived class destructor is called when
    // deleting an object via a base class pointer.
    virtual ~Animal() = default; // Use = default for trivial destructor
};

// Derived class Dog
class Dog : public Animal {
public:
    // Implement makeSound() for Dog.
    // 'const' indicates the method does not modify the object's state.
    // 'override' explicitly states that this method overrides a base class method,
    // improving readability and compile-time error checking.
    void makeSound() const override {
        std::cout << "Woof!\n"; // Use '\n' for efficiency instead of std::endl
    }

    // Default destructor for Dog
    ~Dog() = default;
};

// Derived class Cat
class Cat : public Animal {
public:
    // Implement makeSound() for Cat.
    void makeSound() const override {
        std::cout << "Meow!\n"; // Use '\n' for efficiency
    }

    // Default destructor for Cat
    ~Cat() = default;
};

int main() {
    // Demonstrate polymorphism using smart pointers (std::unique_ptr)
    // for automatic memory management and good practice.
    std::cout << "Creating animals using unique_ptr:\n";

    std::unique_ptr<Animal> myDog = std::make_unique<Dog>();
    std::unique_ptr<Animal> myCat = std::make_unique<Cat>();

    std::cout << "\nDog's sound: ";
    myDog->makeSound(); // Calls Dog::makeSound()

    std::cout << "Cat's sound: ";
    myCat->makeSound(); // Calls Cat::makeSound()

    // When myDog and myCat go out of scope, their destructors
    // (Dog's/Cat's then Animal's) will be correctly called due to the virtual destructor.
    std::cout << "\nAnimals will be automatically destroyed when unique_ptr goes out of scope.\n";

    return 0;
}