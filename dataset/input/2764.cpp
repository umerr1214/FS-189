#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
    virtual std::string sound() const { return "Generic animal sound."; }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
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
            return animal_in_display->sound();
        }
        return "No animal in display.";
    }
    // Missing semicolon here will cause a syntax error
}

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