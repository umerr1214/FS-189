#include <iostream>

class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl; // Logical Error: Dog makes Cat's sound
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Dog myDog;
    Cat myCat;

    Animal* animal1 = &myDog;
    Animal* animal2 = &myCat;

    animal1->makeSound(); // Will print "Meow!" (incorrect for Dog)
    animal2->makeSound(); // Will print "Meow!" (correct for Cat)

    return 0;
}