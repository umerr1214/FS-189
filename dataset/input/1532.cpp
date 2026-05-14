#include <iostream>
#include <cstdio> // For printf and fprintf

// Abstract base class Animal
class Animal {
public:
    // Pure virtual function
    virtual void makeSound() = 0;

    // Destructor (non-virtual, but not the primary issue here, just a minor oversight in a readability context)
    ~Animal() {
        // std::cout << "Animal destructor called.\n";
    }
};

// Concrete class Dog
class Dog : public Animal {
public:
    void makeSound() override {
        const char* dogSound = "Woof!"; // C-style string
        printf("%s\n", dogSound); // Using printf, less C++ idiomatic than std::cout
    }
};

// Concrete class Cat
class Cat : public Animal {
public:
    void makeSound() override {
        char catSound[] = {'M', 'e', 'o', 'w', '!', '\0'}; // C-style string array
        std::fprintf(stdout, "%s\n", catSound); // Using fprintf to stdout, less C++ idiomatic
    }
};

int main() {
    // Demonstrate polymorphism
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    myDog->makeSound(); // Dog makes sound
    myCat->makeSound(); // Cat makes sound

    // Clean up allocated memory
    delete myDog;
    delete myCat;

    return 0;
}