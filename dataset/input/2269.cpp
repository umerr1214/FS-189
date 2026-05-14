#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Player {
public:
    std::string name;

protected:
    int health;

private:
    int score;

public:
    Player(std::string n, int h, int s) : name(n), health(h), score(s) {}

    int getScore() const {
        return score;
    }

    // A getter for health for demonstration in main, but not used by Wizard for modification.
    int getHealth() const {
        return health;
    }
};

class Wizard : public Player {
public:
    Wizard(std::string n, int h, int s) : Player(n, h, s) {}

    void displayWizardInfo() const {
        std::cout << "Wizard Name: " << name << std::endl;
        std::cout << "Current Health: " << health << std::endl;
        std::cout << "Score (via getter): " << getScore() << std::endl;
    }

    // Robustness Issue: Allows health to go below zero without any checks.
    // In a game context, health is typically expected to be non-negative.
    void modifyHealth(int amount) {
        health += amount;
        std::cout << name << "'s health changed by " << amount << ". New health: " << health << std::endl;
    }
};

// Driver code
int main() {
    std::cout << "--- Test Case 1: Initial state and basic damage ---" << std::endl;
    Wizard gandalf("Gandalf", 100, 1500);
    gandalf.displayWizardInfo();
    gandalf.modifyHealth(-30); // Damage
    gandalf.displayWizardInfo();
    std::cout << std::endl;

    std::cout << "--- Test Case 2: Demonstrating robustness issue - health going below zero ---" << std::endl;
    Wizard merlin("Merlin", 20, 1000);
    merlin.displayWizardInfo();
    merlin.modifyHealth(-50); // Damage that makes health negative
    merlin.displayWizardInfo();
    std::cout << std::endl;

    return 0;
}