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
        std::cout << "Animal's current weight: " << weight << " kg." << std::endl;
    }
}; // Missing semicolon here intentionally for syntax error

class Dog : public Animal {
public:
    Dog(int w) : Animal(w) {
        std::cout << "Dog created with initial weight: " << weight << " kg." << std::endl;
    }

    void bark() {
        std::cout << "Woof! My weight is " << weight << " kg." << std::endl;
    }

    void setDogWeight(int newWeight) {
        weight = newWeight; // Dog can access protected member
        std::cout << "Dog's weight updated to: " << weight << " kg." << std::endl;
    }
};

// External non-member function - cannot access protected members directly
void demonstrateExternalAccess(Animal& animal) {
    // This line would cause a semantic error (access violation) if uncommented:
    // std::cout << "Attempting to access Animal's weight from external function: " << animal.weight << std::endl;
    std::cout << "\n--- External Access Demonstration ---" << std::endl;
    std::cout << "External function cannot directly access Animal's protected 'weight'." << std::endl;
    animal.showAnimalWeight(); // Can access public methods
    std::cout << "-----------------------------------" << std::endl;
}

int main() {
    // This part will not compile due to the syntax error above
    Animal genericAnimal(50);
    Dog myDog(20);

    myDog.bark();
    myDog.setDogWeight(25);
    myDog.bark();

    // Attempting to access protected member from main (non-derived, non-friend)
    // This would be a semantic error if the syntax error didn't prevent compilation
    // std::cout << "Attempting to access genericAnimal.weight from main: " << genericAnimal.weight << std::endl;

    demonstrateExternalAccess(genericAnimal);

    return 0;
}