#include <iostream>

class Animal {
public:
    // Make makeSound pure virtual, making Animal an abstract class
    virtual void makeSound() = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    // Semantic error: Forgot to implement makeSound, making Cat an abstract class
    // This will prevent instantiation of Cat objects
    // void makeSound() override {
    //     std::cout << "Meow!" << std::endl;
    // }
};

int main() {
    Animal* myDog = new Dog();
    // This line will cause a semantic error: cannot instantiate abstract class 'Cat'
    Animal* myCat = new Cat(); 

    std::cout << "Dog says: ";
    myDog->makeSound();

    std::cout << "Cat says: ";
    myCat->makeSound();

    delete myDog;
    delete myCat;

    return 0;
}