#include <iostream>
#include <vector>
#include <string> // Used to simulate a resource in derived classes

// Abstract base class without a virtual destructor
class Animal {
public:
    virtual void makeSound() = 0;
    // Missing virtual destructor. This is a robustness issue.
    // When a derived object is deleted via a base class pointer,
    // only the base class destructor will be called, leading to
    // potential resource leaks or undefined behavior for derived class resources.
    ~Animal() {
        // std::cout << "Animal destructor called." << std::endl; // For tracing
    }
};

class Dog : public Animal {
private:
    std::string dogSpecificResource; // Simulates a resource that needs cleanup
public:
    Dog(const std::string& resourceName = "bone") : dogSpecificResource(resourceName) {}
    void makeSound() override {
        std::cout << "Woof! (holding " << dogSpecificResource << ")" << std::endl;
    }
    ~Dog() override {
        // std::cout << "Dog destructor called for resource: " << dogSpecificResource << std::endl; // For tracing
        // In a real application, this would deallocate or release dogSpecificResource
        dogSpecificResource = ""; // Simulate resource cleanup
    }
};

class Cat : public Animal {
private:
    std::string catSpecificResource; // Simulates a resource that needs cleanup
public:
    Cat(const std::string& resourceName = "toy mouse") : catSpecificResource(resourceName) {}
    void makeSound() override {
        std::cout << "Meow! (playing with " << catSpecificResource << ")" << std::endl;
    }
    ~Cat() override {
        // std::cout << "Cat destructor called for resource: " << catSpecificResource << std::endl; // For tracing
        // In a real application, this would deallocate or release catSpecificResource
        catSpecificResource = ""; // Simulate resource cleanup
    }
};

int main() {
    std::vector<Animal*> animals;
    animals.push_back(new Dog("Max's favorite bone"));
    animals.push_back(new Cat("Lucy's yarn ball"));
    animals.push_back(new Dog("Buddy's chew toy"));

    std::cout << "Animals making sounds:" << std::endl;
    for (Animal* animal : animals) {
        animal->makeSound();
    }
    std::cout << std::endl;

    std::cout << "Attempting to delete animals..." << std::endl;
    // This loop demonstrates the robustness issue:
    // When 'delete animal' is called, if Animal's destructor is not virtual,
    // only Animal's destructor is called, not Dog's or Cat's.
    // This means dogSpecificResource and catSpecificResource's simulated
    // cleanup in their respective destructors will not occur.
    for (Animal* animal : animals) {
        delete animal;
    }
    std::cout << "Deletion process complete (potential resource leak)." << std::endl;

    return 0;
}