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
        // LOGICAL ERROR: This method should print the actual 'weight' inherited from Animal,
        // but it prints a hardcoded value, failing to demonstrate access correctly.
        std::cout << "Woof! My weight is 10 kg (this is a fixed value, not the actual inherited weight)." << std::endl;
    }

    void setDogWeight(int newWeight) {
        weight = newWeight; // Dog can access protected member and set it
        std::cout << "Dog's weight updated to: " << weight << " kg." << std::endl;
    }

    void displayActualDogWeight() {
        std::cout << "Dog's actual inherited weight: " << weight << " kg." << std::endl;
    }
};

// External non-member function - correctly shows it cannot access protected members directly
void demonstrateExternalAccess(Animal& animal) {
    // This line would cause a semantic error (access violation) if uncommented:
    // std::cout << "Attempting to access Animal's weight from external function: " << animal.weight << std::endl;
    std::cout << "\n--- External Access Demonstration ---" << std::endl;
    std::cout << "External function cannot directly access Animal's protected 'weight'." << std::endl;
    animal.showAnimalWeight(); // Can only access public methods
    std::cout << "-----------------------------------" << std::endl;
}

int main() {
    Animal genericAnimal(50);
    Dog myDog(20);

    myDog.bark(); // Will print the hardcoded value, demonstrating the logical error
    myDog.displayActualDogWeight(); // This method correctly shows the weight

    myDog.setDogWeight(25);
    myDog.bark(); // Still prints hardcoded value
    myDog.displayActualDogWeight(); // This method correctly shows the updated weight

    // Attempting to access protected member from main (non-derived, non-friend)
    // This would cause a semantic error (compile error) if uncommented:
    // std::cout << "Attempting to access genericAnimal.weight from main: " << genericAnimal.weight << std::endl;
    std::cout << "\nMain function cannot directly access Animal's protected 'weight'." << std::endl;

    demonstrateExternalAccess(genericAnimal);

    return 0;
}