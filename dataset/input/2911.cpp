#include <iostream>
#include <string>
#include <vector>

// Abstract base class Animal
class Animal {
public:
    // Pure virtual method
    virtual void makeSound() = 0;

    // No virtual destructor! This is the robustness issue.
    // If derived classes have resources allocated on the heap,
    // deleting them via an Animal* pointer will lead to memory leaks.
    ~Animal() {
        // std::cout << "Animal destructor called." << std::endl;
    }
};

// Concrete class Dog
class Dog : public Animal {
private:
    std::string* name_tag; // Simulate a resource that needs proper cleanup

public:
    Dog(const std::string& name) : name_tag(new std::string(name)) {}

    void makeSound() override {
        std::cout << "Woof! (from " << *name_tag << ")" << std::endl;
    }

    // This destructor will NOT be called if deleted via Animal*
    ~Dog() {
        // std::cout << "Dog destructor called for " << *name_tag << std::endl;
        delete name_tag;
    }
};

// Concrete class Cat
class Cat : public Animal {
private:
    std::string* favorite_toy; // Simulate another resource

public:
    Cat(const std::string& toy) : favorite_toy(new std::string(toy)) {}

    void makeSound() override {
        std::cout << "Meow! (playing with " << *favorite_toy << ")" << std::endl;
    }

    // This destructor will NOT be called if deleted via Animal*
    ~Cat() {
        // std::cout << "Cat destructor called for toy " << *favorite_toy << std::endl;
        delete favorite_toy;
    }
};

int main() {
    // Demonstrate the robustness issue: memory leak due to missing virtual destructor
    Animal* myDog = new Dog("Buddy");
    Animal* myCat = new Cat("Yarn Ball");

    myDog->makeSound();
    myCat->makeSound();

    // Deleting via base class pointer without virtual destructor
    // will only call Animal's destructor, leading to memory leaks
    // for name_tag and favorite_toy.
    delete myDog;
    delete myCat;

    // To make the issue more apparent in a real scenario,
    // one might run a memory leak detector.
    // For this example, the code will run, but with potential leaks.

    // Another example of direct object creation (no leak here)
    Dog stackDog("Rex");
    Cat stackCat("Mouse");
    stackDog.makeSound();
    stackCat.makeSound();

    return 0;
}