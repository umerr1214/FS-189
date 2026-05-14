#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
    // Semantic Error: The 'sound()' method is not declared virtual.
    // This prevents polymorphic behavior when calling 'sound()' through an 'Animal*' pointer.
    std::string sound() const { return "Generic animal sound."; }
    virtual ~Animal() = default; // Destructor is virtual, but sound() is not.
};

class Dog : public Animal {
public:
    // This 'sound()' method effectively 'hides' the base class method,
    // rather than 'overriding' it polymorphically because Animal::sound() is not virtual.
    std::string sound() const override { return "Woof!"; }
};

class Cat : public Animal {
public:
    std::string sound() const override { return "Meow!"; }
};

class Zoo {
private:
    Animal* animal_in_display;

public:
    Zoo(Animal* animal) : animal_in_display(animal) {}

    std::string makeSound() const {
        if (animal_in_display) {
            // Due to Animal::sound() not being virtual, this will always call Animal::sound()
            // even if animal_in_display points to a Dog or Cat.
            return animal_in_display->sound();
        }
        return "No animal in display.";
    }
    // Assuming Zoo does not own the Animal* for simplicity, no destructor needed.
};

int main() {
    Dog myDog;
    Cat myCat;

    Zoo dogExhibit(&myDog);
    std::cout << "Dog exhibit says: " << dogExhibit.makeSound() << std::endl;

    Zoo catExhibit(&myCat);
    std::cout << "Cat exhibit says: " << catExhibit.makeSound() << std::endl;

    Animal genericAnimal;
    Zoo genericExhibit(&genericAnimal);
    std::cout << "Generic exhibit says: " << genericExhibit.makeSound() << std::endl;

    return 0;
}