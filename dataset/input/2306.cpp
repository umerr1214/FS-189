#include <iostream> // Included but not primarily used for output
#include <cstdio>   // For printf
#include <string>   // For std::string

// Abstract base class
class Animal {
public:
    virtual void makeSound() = 0;
    // A virtual destructor is present, but the readability/efficiency issues are elsewhere.
    virtual ~Animal() = default; 
};

// Concrete derived class Dog
class Dog : public Animal {
public:
    // READABILITY/EFFICIENCY ISSUE: No 'override' keyword, which is a good practice for clarity.
    void makeSound() /* no override */ {
        // READABILITY/EFFICIENCY ISSUE: Redundant string creation on each call.
        std::string sound_dog = "Woof!"; 
        // READABILITY/EFFICIENCY ISSUE: Using C-style printf instead of C++ streams.
        printf("%s\n", sound_dog.c_str()); 
    }
};

// Concrete derived class Cat
class Cat : public Animal {
public:
    // READABILITY/EFFICIENCY ISSUE: No 'override' keyword.
    void makeSound() /* no override */ {
        // READABILITY/EFFICIENCY ISSUE: Redundant string creation on each call.
        std::string cat_sound = "Meow!"; 
        // READABILITY/EFFICIENCY ISSUE: Using C-style printf instead of C++ streams.
        printf("%s\n", cat_sound.c_str()); 
    }
};

// Driver code for testing
int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    printf("--- Animals Making Sounds ---\n");
    myDog->makeSound();
    myCat->makeSound();

    printf("\n--- Deleting Animals ---\n");
    delete myDog; // Correctly calls virtual destructor
    delete myCat; // Correctly calls virtual destructor

    printf("\n--- Program End ---\n");

    return 0;
}