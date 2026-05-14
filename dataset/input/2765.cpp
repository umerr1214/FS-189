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
    // Logical Error: The constructor takes an Animal* but then immediately creates a new base Animal
    // object, effectively ignoring the specific animal passed in and losing polymorphism.
    Zoo(Animal* animal) : animal_in_display(new Animal()) {
        // The 'animal' parameter is ignored, leading to incorrect behavior.
        // This is a memory leak too, but the primary logical error is failing polymorphism.
    }

    std::string makeSound() const {
        if (animal_in_display) {
            return animal_in_display->sound();
        }
        return "No animal in display.";
    }

    ~Zoo() {
        delete animal_in_display; // Clean up the Animal object created in the constructor
    }
};

int main() {
    Dog myDog;
    Cat myCat;

    Zoo dogExhibit(&myDog); // Pass a Dog, but Zoo's internal animal will be generic
    std::cout << "Dog exhibit says: " << dogExhibit.makeSound() << std::endl;

    Zoo catExhibit(&myCat); // Pass a Cat, but Zoo's internal animal will be generic
    std::cout << "Cat exhibit says: " << catExhibit.makeSound() << std::endl;

    Animal genericAnimal;
    Zoo genericExhibit(&genericAnimal);
    std::cout << "Generic exhibit says: " << genericExhibit.makeSound() << std::endl;

    return 0;
}