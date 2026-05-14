#include <iostream>
#include <string>

// Early Binding (Static Polymorphism) using Function Overloading
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    std::string add(const std::string& s1, const std::string& s2) {
        return s1 + s2;
    }
};

// Late Binding (Dynamic Polymorphism) using Virtual Functions
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal makes a generic sound." << std::endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Dog barks: Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    // Logical Error: Cat's makeSound incorrectly prints Dog's sound
    void makeSound() const override {
        std::cout << "Cat barks: Woof!" << std::endl; // Should be "Cat meows: Meow!"
    }
};

int main() {
    // Early Binding Example
    std::cout << "--- Early Binding (Function Overloading) ---" << std::endl;
    Calculator calc;
    std::cout << "Sum of integers: " << calc.add(5, 10) << std::endl;
    std::cout << "Sum of doubles: " << calc.add(5.5, 10.5) << std::endl;
    std::cout << "Concatenated strings: " << calc.add("Hello", " World") << std::endl;

    std::cout << "\n--- Late Binding (Virtual Functions) ---" << std::endl;
    // Base class pointers pointing to derived objects
    Animal* myAnimal1 = new Dog();
    Animal* myAnimal2 = new Cat(); // This Cat object will exhibit the logical error
    Animal* myAnimal3 = new Animal();

    myAnimal1->makeSound(); // Calls Dog::makeSound() - Correct
    myAnimal2->makeSound(); // Calls Cat::makeSound() but prints wrong sound - Logical Error
    myAnimal3->makeSound(); // Calls Animal::makeSound() - Correct

    delete myAnimal1;
    delete myAnimal2;
    delete myAnimal3;

    return 0;
}