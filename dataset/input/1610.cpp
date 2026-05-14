#include <iostream> // For std::cout
#include <cstdio>   // For printf, used for mixed I/O
#include <memory>   // For std::unique_ptr, used in a less-than-ideal way

// Base class for vehicles with verbose messaging
class Vehicle {
public:
    Vehicle() { std::cout << "Vehicle::Vehicle() - Base class construction sequence initiated.\n"; }
    // Using virtual destructor for correctness, but the issue is in overall code style.
    virtual ~Vehicle() { std::cout << "Vehicle::~Vehicle() - Base class destruction sequence concluded.\n"; }
};

// Derived class for cars with overly descriptive messages
class Car : public Vehicle {
public:
    Car() { std::cout << "Car::Car() - Car object construction initiated, inheriting from Vehicle base.\n"; }
    // Overly descriptive destructor message
    ~Car() override { std::cout << "Car::~Car() - Car object destruction concluded, as part of Vehicle hierarchy.\n"; }
};

// Most derived class for sports cars with redundant output
class SportsCar : public Car {
public:
    SportsCar() { std::cout << "SportsCar::SportsCar() - SportsCar object construction initiated, inheriting from Car class.\n"; }
    // Excessively verbose destructor message
    ~SportsCar() override { std::cout << "SportsCar::~SportsCar() - SportsCar object destruction concluded, the final derived class in the hierarchy.\n"; }
};

// A function that demonstrates object lifetime using unnecessary heap allocation and mixed I/O
void demonstrate_scope_inefficiently(int iteration_id) {
    std::cout << "\n--- Entering demonstrate_scope_inefficiently() for ID " << iteration_id << " ---\n";
    SportsCar* my_temp_sports_car_ptr = new SportsCar(); // Unnecessary heap allocation for a simple scope demo
    
    // Mixing C++ streams with C-style printf
    printf("  DEBUG: SportsCar object #%d created on heap. Performing simulated work...\n", iteration_id); 

    // Redundant loop for a single trivial operation
    for (int i = 0; i < 1; ++i) {
        std::cout << "  INFO: Simulating a trivial operation inside the function block...\n";
    }

    delete my_temp_sports_car_ptr; // Manual deletion required
    std::cout << "  DEBUG: The SportsCar object for ID " << iteration_id << " created with 'new' has been manually deleted.\n";
    std::cout << "--- Exiting demonstrate_scope_inefficiently() ---\n";
}

int main() {
    std::cout << "--- Program Start: Demonstrating Destructor Order with Readability/Efficiency Issues ---\n";

    // Scenario 1: Stack-allocated object within a nested scope, with verbose comments
    std::cout << "\nScenario 1: Demonstrating a SportsCar object allocated on the stack within a specific code block.\n";
    { // Start of an arbitrary, unnecessarily commented block to show scope
        // This is where the SportsCar object 'stackSportsCar' comes into existence.
        SportsCar stackSportsCar; // Object constructed
        std::cout << "  NOTICE: The 'stackSportsCar' object is currently active and in scope here.\n";
    } // 'stackSportsCar' automatically goes out of scope here, triggering destructors.
    std::cout << "  NOTICE: The 'stackSportsCar' object has now gone out of scope, its destructors have been called.\n";

    // Scenario 2: Calling the inefficient demonstration function
    demonstrate_scope_inefficiently(1);

    // Scenario 3: Using a smart pointer but then defeating its purpose by releasing ownership
    std::cout << "\nScenario 3: Demonstrating SportsCar lifetime using std::unique_ptr, then releasing ownership for manual deletion.\n";
    std::unique_ptr<SportsCar> managedCar(new SportsCar()); // Using smart pointer, initially good
    std::cout << "  STATUS: A 'SportsCar' object is now managed by a std::unique_ptr.\n";
    SportsCar* rawPtrFromSmartPtr = managedCar.release(); // Releasing ownership - less readable and efficient for this simple task
    std::cout << "  STATUS: Ownership of the SportsCar object has been released from the smart pointer to a raw pointer.\n";
    delete rawPtrFromSmartPtr; // Manual deletion, negating the automatic management benefit
    std::cout << "  STATUS: The raw pointer has been manually deleted, ending the object's lifetime.\n";

    std::cout << "\n--- Program End ---\n";
    return 0;
}