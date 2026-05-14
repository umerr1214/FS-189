#include <iostream>
#include <string>
#include <vector>
#include <sstream> // For string parsing in modifyHealth and driver output

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

    int getHealth() const { // Added for driver to verify health
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

    // Readability/Efficiency Issue: Takes a string command and parses it.
    // This is less efficient than directly passing an integer amount,
    // and less readable/intuitive for a simple health modification.
    void modifyHealth(const std::string& command) {
        std::stringstream ss(command);
        std::string action;
        int amount;

        ss >> action >> amount;

        if (action == "heal") {
            health += amount;
            std::cout << name << " healed by " << amount << ". New health: " << health << std::endl;
        } else if (action == "damage") {
            health -= amount;
            std::cout << name << " damaged by " << amount << ". New health: " << health << std::endl;
        } else {
            std::cout << "Invalid command: " << command << ". Health remains: " << health << std::endl;
        }
    }
};

// Driver code
int main() {
    std::cout << "--- Test Case 1: Healing with string command ---" << std::endl;
    Wizard elara("Elara", 80, 1200);
    elara.displayWizardInfo();
    elara.modifyHealth("heal 20");
    elara.displayWizardInfo();
    std::cout << std::endl;

    std::cout << "--- Test Case 2: Damaging with string command ---" << std::endl;
    Wizard zoltan("Zoltan", 150, 1800);
    zoltan.displayWizardInfo();
    zoltan.modifyHealth("damage 50");
    zoltan.displayWizardInfo();
    std::cout << std::endl;

    std::cout << "--- Test Case 3: Invalid command ---" << std::endl;
    Wizard arcane("Arcane", 75, 900);
    arcane.displayWizardInfo();
    arcane.modifyHealth("boost 10");
    arcane.displayWizardInfo();
    std::cout << std::endl;

    return 0;
}