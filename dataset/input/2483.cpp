#include <iostream>
#include <string>

class SecretAgent {
public:
    std::string codename;

    SecretAgent(std::string code, std::string identity, std::string briefing)
        : codename(code), trueIdentity(identity), missionBriefing(briefing) {}

    void displayCodename() const {
        std::cout << "Agent Codename: " << codename << std::endl;
    }

    // A public method that accidentally reveals a part of the trueIdentity,
    // thereby logically undermining the 'private' access level intent.
    void revealAgentHint() const {
        if (!trueIdentity.empty()) {
            std::cout << "Hint for Agent's Identity: First letter is '" << trueIdentity[0] << "'" << std::endl;
        } else {
            std::cout << "No identity hint available." << std::endl;
        }
    }

private:
    std::string trueIdentity;

protected:
    std::string missionBriefing;

    void revealMissionBriefingInternal() const {
        std::cout << "Internal Briefing Access: " << missionBriefing << std::endl;
    }
};

class Handler : public SecretAgent {
public:
    Handler(std::string code, std::string identity, std::string briefing, std::string handlerID)
        : SecretAgent(code, identity, briefing), handlerID_(handlerID) {}

    void accessAgentInfo() const {
        std::cout << "\n--- Handler Accessing Agent Info ---" << std::endl;
        // Access public member (permitted)
        std::cout << "Handler can see Codename: " << codename << std::endl;

        // Access protected member (permitted for derived class)
        // This method just prints a generic message, not the actual missionBriefing
        // which is a logical error in demonstrating the access.
        std::cout << "Handler attempts to access Mission Briefing." << std::endl;
        // revealMissionBriefingInternal(); // This would correctly show it, but is omitted for the logical error
        std::cout << "Mission briefing details are handled internally by the agent's class." << std::endl; // Misleading or incomplete access demonstration

        // Attempt to access private member (not permitted - will cause compile error if uncommented)
        // std::cout << "Handler trying to access True Identity: " << trueIdentity << std::endl;
        std::cout << "Handler cannot directly access True Identity (private)." << std::endl;
    }

private:
    std::string handlerID_;
};

int main() {
    SecretAgent agent1("Phoenix", "John Doe", "Infiltrate organization X.");
    Handler handler1("Viper", "Jane Smith", "Extract target Y.", "Alpha7");

    std::cout << "--- Outside Access (from main) ---" << std::endl;
    // Access public member (permitted)
    agent1.displayCodename();
    std::cout << "Main can see Agent Codename: " << agent1.codename << std::endl;

    // Logical error: The revealAgentHint method provides a 'hint' about a private member,
    // which, while not direct access, undermines the privacy concept.
    agent1.revealAgentHint();

    // Attempt to access private member (not permitted - will cause compile error if uncommented)
    // std::cout << "Main trying to access True Identity: " << agent1.trueIdentity << std::endl;
    std::cout << "Main cannot directly access True Identity (private)." << std::endl;

    // Attempt to access protected member (not permitted from outside the class or derived classes)
    // std::cout << "Main trying to access Mission Briefing: " << agent1.missionBriefing << std::endl;
    std::cout << "Main cannot directly access Mission Briefing (protected)." << std::endl;

    handler1.accessAgentInfo();

    return 0;
}