#include <iostream> // Needed for std::cout
#include <vector> // Not strictly needed, but often included
// No override keyword, inconsistent formatting, raw pointers in main

// Abstract Animal class
class Animal
{
public:
    // Pure virtual function
    virtual void makeSound() = 0;

    // Non-virtual destructor. Not a robustness issue in this specific case
    // as no resources are managed by derived classes, but still not idiomatic for polymorphic bases.
    ~Animal() {
        // std::cout << "Base Animal destructor." << std::endl;
    }
};

// Dog class
class Dog : public Animal
{
public:
    // READABILITY ISSUE: Missing 'override' keyword.
    // This makes the code less clear about the intent to override and
    // prevents compile-time checks if the base method signature changes.
    void makeSound()
    {
        std::cout << "Woof!" << std::endl;
    }
};

// Cat class
class Cat : public Animal
{
public:
    // READABILITY ISSUE: Missing 'override' keyword.
    void makeSound()
    {
        std::cout << "Meow!" << std::endl;
    }
};

int main()
{
    // READABILITY/EFFICIENCY ISSUE: Inconsistent indentation and formatting.
    // READABILITY/EFFICIENCY ISSUE: Using raw pointers and new/delete unnecessarily
    // for objects that could be stack-allocated or managed by smart pointers.
    // This approach is more verbose, prone to memory leaks if 'delete' is forgotten,
    // and generally considered less safe and less efficient (developer time) in modern C++.
    Animal* myDog = new Dog();
      Animal* myCat = new Cat(); // Inconsistent indentation

    myDog->makeSound();
    myCat->makeSound();

    // Manual memory management, prone to errors and less readable
    delete myDog;
     delete myCat; // Inconsistent indentation

    return 0;
}