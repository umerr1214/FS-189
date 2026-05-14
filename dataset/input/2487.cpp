#include <iostream>
#include <string>

class SecretAgent {
public:
    std::string codename; // Public: Accessible from anywhere

protected:
    std::string missionBriefing; // Protected: Accessible by derived classes

private:
    std::string trueIdentity; // Private: Accessible only by members of SecretAgent

public:
    // Constructor using initializer list for clean and efficient initialization
    SecretAgent(const std::string& name, const std::string& identity, const std::string& briefing)
        : codename(name), trueIdentity(identity), missionBriefing(briefing) {}

    // Public method to provide controlled read-only access to private trueIdentity
    std::string getTrueIdentity() const {
        return "True Identity (via public method): " + trueIdentity;
    }

    // Public method to display codename
    void displayCodename() const {
        std::cout << "Agent Codename: " << codename << std::endl;
    }

    // Public method to report status, demonstrating access limitations
    void reportStatus() const {
        std::cout << "Secret Agent Status Report:" << std::endl;
        std::cout << "  Codename: " << codename << std::endl;
        std::cout << "  " << getTrueIdentity() << std::endl;
        // std::cout << "  Mission Briefing: " << missionBriefing << std::endl; // Protected, not directly accessible from base class public method
        std::cout << "  Mission Briefing: [Only accessible by derived classes or friends]" << std::endl;
    }
};

class Handler : public SecretAgent {
public:
    // Constructor for Handler, calls base class constructor using initializer list
    Handler(const std::string& name, const std::string& identity, const std::string& briefing)
        : SecretAgent(name, identity, briefing) {}

    // Public method to access and display protected missionBriefing (permitted)
    void reviewMissionBriefing() const {
        std::cout << "Handler '" << codename << "' reviewing mission briefing: " << missionBriefing << std::endl;
    }

    // Public method to demonstrate inability to access private trueIdentity directly
    void attemptPrivateAccess() const {
        std::cout << "Handler '" << codename << "' attempting to access private trueIdentity: [Not permitted directly]" << std::endl;
        // std::cout << trueIdentity << std::endl; // This line would cause a compilation error
    }

    // A method to demonstrate inherited public and protected access
    void reportHandlerInfo() const {
        std::cout << "Handler Info: " << std::endl;
        std::cout << "  Codename: " << codename << std::endl; // Inherited public
        reviewMissionBriefing(); // Accesses inherited protected
        // attemptPrivateAccess(); // Demonstrates private access restriction
    }
};

int main() {
    // Create an instance of SecretAgent
    SecretAgent agent1("Ghost", "Ethan Hunt", "Retrieve the stolen data.");

    // Create an instance of Handler (derived class)
    Handler handler1("Specter", "Ilsa Faust", "Provide tactical support for Ghost.");

    std::cout << "--- Demonstrating Access from Outside (main function) ---" << std::endl;

    // 1. Accessing Public Members: Permitted
    std::cout << "\nAccessing Public Member (codename) of SecretAgent:" << std::endl;
    std::cout << "Agent1's Codename: " << agent1.codename << std::endl;
    agent1.codename = "Phantom"; // Can modify directly
    std::cout << "Agent1's Codename (modified): " << agent1.codename << std::endl;
    agent1.displayCodename();

    // 2. Accessing Private Members: Not Permitted Directly
    std::cout << "\nAccessing Private Member (trueIdentity) of SecretAgent:" << std::endl;
    // std::cout << agent1.trueIdentity << std::endl; // ERROR: 'trueIdentity' is private
    std::cout << "Direct access to agent1.trueIdentity: [Compilation Error]" << std::endl;
    std::cout << agent1.getTrueIdentity() << std::endl; // Permitted via public getter method

    // 3. Accessing Protected Members: Not Permitted Directly
    std::cout << "\nAccessing Protected Member (missionBriefing) of SecretAgent:" << std::endl;
    // std::cout << agent1.missionBriefing << std::endl; // ERROR: 'missionBriefing' is protected
    std::cout << "Direct access to agent1.missionBriefing: [Compilation Error]" << std::endl;

    std::cout << "\n--- Demonstrating Access from Derived Class (Handler) ---" << std::endl;

    // 1. Accessing Public Members (inherited): Permitted
    std::cout << "\nAccessing Public Member (codename) of Handler:" << std::endl;
    std::cout << "Handler1's Codename: " << handler1.codename << std::endl;
    handler1.displayCodename(); // Inherited public method

    // 2. Accessing Protected Members (inherited): Permitted
    std::cout << "\nAccessing Protected Member (missionBriefing) from Handler:" << std::endl;
    handler1.reviewMissionBriefing(); // Handler method accessing inherited protected member

    // 3. Accessing Private Members (inherited): Not Permitted Directly
    std::cout << "\nAccessing Private Member (trueIdentity) from Handler:" << std::endl;
    handler1.attemptPrivateAccess(); // Handler method attempting (and correctly failing) direct access
    std::cout << handler1.getTrueIdentity() << std::endl; // Access via inherited public getter method

    std::cout << "\n--- Summary Reports ---" << std::endl;
    agent1.reportStatus();
    std::cout << std::endl;
    handler1.reportHandlerInfo();

    return 0;
}