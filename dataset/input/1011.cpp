#include <iostream>
#include <string>

class Animal {
protected:
    int weight;
public:
    Animal(int w = 0) : weight(w) {
        std::cout << "Animal created with weight: " << weight << " kg." << std::endl;
    }
    void showAnimalWeight() {
        std::cout << "Animal's current weight (from public method): " << weight << " kg." << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(int w) : Animal(w) {
        std::cout << "Dog created with initial weight: " << weight << " kg." << std::endl;
    }

    void bark() {
        std::cout << "Woof! My weight is " << weight << " kg." << std::endl; // Dog correctly accesses protected member
    }

    void setDogWeight(int newWeight) {
        weight = newWeight; // Dog can access protected member
        std::cout << "Dog's weight updated to: " << weight << " kg." << std::endl;
    }
};

// External non-member function
void demonstrateExternalAccess(Animal& animal) {
    // SEMANTIC ERROR: Attempting to access protected member 'weight' from a non-member, non-friend function
    std::cout << "Attempting to access Animal's weight from external function: " << animal.weight << " kg." << std::endl;
}

int main() {
    Animal genericAnimal(50);
    Dog myDog(20);

    myDog.bark();
    myDog.setDogWeight(25);
    myDog.bark();

    // SEMANTIC ERROR: Attempting to access protected member 'weight' from main (non-derived, non-friend)
    std::cout << "Attempting to access genericAnimal.weight from main: " << genericAnimal.weight << " kg." << std::endl;

    demonstrateExternalAccess(genericAnimal);

    return 0;
}