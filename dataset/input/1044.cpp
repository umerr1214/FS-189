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
    // Semantic Error: makeSound is not virtual, preventing late binding for this function
    void makeSound() const { // Should be 'virtual void makeSound() const'
        std::cout << "Animal makes a generic sound." << std::endl;
    }
    virtual ~Animal() {} // Destructor is virtual, but makeSound is the issue
};

class Dog : public Animal {
public:
    // This 'makeSound' now hides Animal::makeSound, doesn't override it polymorphically
    void makeSound() const { // No 'override' keyword used, so it compiles and hides the base method
        std::cout << "Dog barks: Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    // This 'makeSound' now hides Animal::makeSound, doesn't override it polymorphically
    void makeSound() const { // No 'override' keyword used, so it compiles and hides the base method
        std::cout << "Cat meows: Meow!" << std::endl;
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
    Animal* myAnimal2 = new Cat();
    Animal* myAnimal3 = new Animal();

    myAnimal1->makeSound(); // Calls Animal::makeSound() due to semantic error (missing virtual)
    myAnimal2->makeSound(); // Calls Animal::makeSound() due to semantic error (missing virtual)
    myAnimal3->makeSound(); // Calls Animal::makeSound() - Correct (base type)

    delete myAnimal1;
    delete myAnimal2;
    delete myAnimal3;

    return 0;
}