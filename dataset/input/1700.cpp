#include <iostream>
#include <string>

// Base class
class Animal {
public: // Readability/Efficiency Issue: Public members
    std::string species_name; // Verbose member name

    Animal(const std::string& s) : species_name(s) {
        std::cout << "->>> Animal object being constructed. Species: " << this->species_name << " <<<-" << std::endl; // Excessive 'this->' and verbose output
    }

    ~Animal() {
        std::cout << "->>> Animal object being destructed. Species: " << this->species_name << " <<<-" << std::endl;
    }

    void perform_eating_action() { // Verbose method name, not const
        std::cout << "    ==========================================================" << std::endl;
        std::cout << "    The " << this->species_name << " is now commencing its eating activity." << std::endl;
        std::cout << "    It consumes sustenance for energy and survival." << std::endl;
        std::cout << "    This is a fundamental biological process." << std::endl;
        std::cout << "    ==========================================================" << std::endl;
    }
};

// Derived class 1
class Mammal : public Animal {
public: // Readability/Efficiency Issue: Public members
    std::string fur_color_description; // Verbose member name

    Mammal(const std::string& s, const std::string& fc)
        : Animal(s), fur_color_description(fc) {
        std::cout << "->>> Mammal object being constructed. Species: " << this->species_name << ", Fur Color: " << this->fur_color_description << " <<<-" << std::endl;
    }

    ~Mammal() {
        std::cout << "->>> Mammal object being destructed. Species: " << this->species_name << " <<<-" << std::endl;
    }

    void execute_birthing_process() { // Verbose method name, not const
        std::cout << "    ----------------------------------------------------------" << std::endl;
        std::cout << "    The " << this->species_name << " (a mammal) is initiating the process of giving birth to live offspring." << std::endl;
        std::cout << "    This is a characteristic reproductive method for this class of animals." << std::endl;
        std::cout << "    ----------------------------------------------------------" << std::endl;
    }
};

// Derived class 2
class Dog : public Mammal {
public: // Readability/Efficiency Issue: Public members
    std::string dog_breed_type; // Verbose member name

    Dog(const std::string& s, const std::string& fc, const std::string& b)
        : Mammal(s, fc), dog_breed_type(b) {
        std::cout << "->>> Dog object being constructed. Species: " << this->species_name << ", Breed: " << this->dog_breed_type << " <<<-" << std::endl;
    }

    ~Dog() {
        std::cout << "->>> Dog object being destructed. Species: " << this->species_name << ", Breed: " << this->dog_breed_type << " <<<-" << std::endl;
    }

    void perform_barking_sound() { // Verbose method name, not const
        std::cout << "    **********************************************************" << std::endl;
        std::cout << "    The " << this->dog_breed_type << " dog, a member of the " << this->species_name << " species, is emitting its characteristic vocalization: Woof! Woof!" << std::endl;
        std::cout << "    This action serves various communicative purposes." << std::endl;
        std::cout << "    **********************************************************" << std::endl;
    }
};

void run_demonstration() {
    std::cout << "--- Initiating demonstration of multi-level inheritance ---" << std::endl;
    Dog my_canine_companion("Domestic Dog", "Golden-Brown", "Golden Retriever");
    std::cout << "--- Object constructed. Now calling methods: ---" << std::endl;

    my_canine_companion.perform_eating_action();
    my_canine_companion.execute_birthing_process();
    my_canine_companion.perform_barking_sound();

    std::cout << "--- Demonstration concluded. ---" << std::endl;
}

int main() {
    run_demonstration();
    return 0;
}