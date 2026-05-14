#include <iostream>
#include <string>

// Abstract base class
class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {}
};

// Concrete class Dog
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl; // LOGICAL ERROR: Dog should say Woof!
    }
};

// Concrete class Cat
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl; // LOGICAL ERROR: Cat should say Meow!
    }
};

int main() {
    Dog myDog;
    Cat myCat;

    std::cout << "Testing concrete instances:\n";
    std::cout << "Dog says: ";
    myDog.makeSound(); // Expected: Woof!, Actual: Meow!

    std::cout << "Cat says: ";
    myCat.makeSound(); // Expected: Meow!, Actual: Woof!

    // Demonstrate polymorphism with pointers
    Animal* polymorphicDog = new Dog();
    Animal* polymorphicCat = new Cat();

    std::cout << "\nTesting polymorphic instances:\n";
    std::cout << "Polymorphic Dog says: ";
    polymorphicDog->makeSound(); // Expected: Woof!, Actual: Meow!

    std::cout << "Polymorphic Cat says: ";
    polymorphicCat->makeSound(); // Expected: Meow!, Actual: Woof!

    delete polymorphicDog;
    delete polymorphicCat;

    return 0;
}