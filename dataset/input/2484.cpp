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
        std::cout << "Handler can access Mission Briefing: " << missionBriefing << std::endl;
        revealMissionBriefingInternal(); // Can call protected method

        // Attempt to access private member (not permitted - this will cause a semantic error)
        std::cout << "Handler trying to access True Identity: " << trueIdentity << std::endl;
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

    // Attempt to access private member (not permitted - this will cause a semantic error)
    std::cout << "Main trying to access True Identity: " << agent1.trueIdentity << std::endl;

    // Attempt to access protected member (not permitted from outside the class or derived classes - this will cause a semantic error)
    std::cout << "Main trying to access Mission Briefing: " << agent1.missionBriefing << std::endl;

    handler1.accessAgentInfo();

    return 0;
}