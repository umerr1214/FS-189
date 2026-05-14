#include <iostream>
#include <string>

class Player {
public:
    std::string name;
protected:
    int health;
private:
    int score;

public:
    Player(std::string n, int h, int s) : name(n), health(h), score(s) {}

    void displayPlayerInfo() const {
        std::cout << "Player Name: " << name << std::endl;
        std::cout << "Player Health: " << health << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

class Wizard : public Player {
public:
    Wizard(std::string n, int h, int s) : Player(n, h, s) {}

    // Demonstrate accessing name directly
    void castSpell() {
        std::cout << name << " casts a spell!" << std::endl;
        // Attempt to modify health through a member function
        modifyHealth(10); // Increase health by 10
    }

    // Member function to modify health
    void modifyHealth(int amount) {
        health += amount; // Accessing protected member 'health'
        std::cout << name << "'s health modified to: " << health << std::endl;
    }

    void displayWizardInfo() const {
        std::cout << "Wizard Name: " << name << std::endl;
        std::cout << "Wizard Health: " << health << std::endl;
    }
};

int main() {
    Wizard gandalf("Gandalf", 100, 500);
    gandalf.displayWizardInfo();
    gandalf.castSpell();
    gandalf.displayWizardInfo();

    return 0;
}