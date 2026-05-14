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

    // Public getter for score (since it's private)
    int getScore() const {
        return score;
    }

    // Public getter for health (for external observation, not for modification by Wizard)
    int getHealth() const {
        return health;
    }
};

class Wizard : public Player {
public:
    Wizard(std::string n, int h, int s) : Player(n, h, s) {}

    // Demonstrates accessing 'name' directly (public member)
    // Demonstrates accessing 'health' directly (protected member)
    void displayWizardInfo() const {
        std::cout << "Wizard Name: " << name << std::endl; // Direct access to public member 'name'
        std::cout << "Current Health: " << health << std::endl; // Direct access to protected member 'health'
        std::cout << "Score (via getter): " << getScore() << std::endl; // Access private 'score' via public getter
    }

    // Member function to modify 'health' (protected member)
    // Clear, direct, and efficient way to modify health.
    void changeHealth(int amount) {
        health += amount;
        std::cout << name << "'s health changed by " << amount << ". New health: " << health << std::endl;
    }
};

// Driver code
int main() {
    // Test Case 1: Initial creation and display
    Wizard gandalf("Gandalf", 100, 1500);
    std::cout << "--- Initial State ---" << std::endl;
    gandalf.displayWizardInfo();
    std::cout << std::endl;

    // Test Case 2: Modifying health (healing)
    std::cout << "--- Healing ---" << std::endl;
    gandalf.changeHealth(20);
    gandalf.displayWizardInfo();
    std::cout << std::endl;

    // Test Case 3: Modifying health (damage)
    std::cout << "--- Damaging ---" << std::endl;
    gandalf.changeHealth(-50);
    gandalf.displayWizardInfo();
    std::cout << std::endl;

    // Test Case 4: Another Wizard instance
    Wizard merlin("Merlin", 80, 1200);
    std::cout << "--- Another Wizard ---" << std::endl;
    merlin.displayWizardInfo();
    merlin.changeHealth(10);
    merlin.displayWizardInfo();

    return 0;
}