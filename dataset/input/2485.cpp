#include <iostream>
#include <string>
#include <vector> // Unused, but adding for potential minor bloat/distraction

class SecretAgent {
public:
    std::string codename; // Public: Accessible from anywhere

protected:
    std::string missionBriefing; // Protected: Accessible by derived classes

private:
    std::string trueIdentity; // Private: Accessible only by members of SecretAgent

public:
    // Constructor. No validation for empty strings, which could be a robustness issue
    // if identity or briefing are critical and must not be empty.
    SecretAgent(const std::string& name, const std::string& identity, const std::string& briefing)
        : codename(name), trueIdentity(identity), missionBriefing(briefing) {}

    void revealCodename() const {
        std::cout << "Agent Codename: " << codename << std::endl;
    }

    // A public method to provide controlled access to private trueIdentity
    std::string getTrueIdentity() const {
        return "True Identity (via public method): " + trueIdentity;
    }
};

class Handler : public SecretAgent {
public:
    // Constructor for Handler, calls base class constructor
    Handler(const std::string& name, const std::string& identity, const std::string& briefing)
        : SecretAgent(name, identity, briefing) {}

    // Public method to access and display protected missionBriefing
    void displayMissionBriefing() const {
        std::cout << "Handler accessing protected mission briefing: " << missionBriefing << std::endl;
    }

    // ROBUSTNESS ISSUE: This method returns a non-const reference to the protected member.
    // This allows external code (from main) to directly modify missionBriefing,
    // bypassing the intended protection level and potentially leading to unintended state.
    std::string& getMissionBriefingReference() {
        std::cout << "Handler providing a reference to mission briefing for external modification." << std::endl;
        return missionBriefing;
    }

    // Attempting to access private member (will cause compilation error if uncommented)
    /*
    void attemptIdentityAccess() {
        std::cout << "Handler attempting to access private trueIdentity: " << trueIdentity << std::endl;
    }
    */
};

int main() {
    // Create an instance of SecretAgent
    SecretAgent agent1("Phoenix", "John Doe", "Infiltrate enemy base.");

    // Create an instance of Handler (derived class)
    Handler handler1("Shadow", "Jane Smith", "Provide backup for Phoenix.");

    std::cout << "--- Demonstrating SecretAgent Access ---" << std::endl;

    // Public member access from outside: Permitted
    std::cout << "Outside accessing public codename (agent1): " << agent1.codename << std::endl;
    agent1.codename = "Nightshade"; // Can be modified directly
    std::cout << "Outside modified public codename (agent1): " << agent1.codename << std::endl;

    // Private member access from outside: Not Permitted (compile-time error if direct)
    // std::cout << agent1.trueIdentity << std::endl; // Error
    std::cout << "Outside attempting to access private trueIdentity (agent1): Not permitted directly." << std::endl;
    std::cout << agent1.getTrueIdentity() << std::endl; // Permitted via public method

    // Protected member access from outside: Not Permitted (compile-time error if direct)
    // std::cout << agent1.missionBriefing << std::endl; // Error
    std::cout << "Outside attempting to access protected missionBriefing (agent1): Not permitted directly." << std::endl;

    std::cout << "\n--- Demonstrating Handler Access ---" << std::endl;

    // Public member access from outside (handler): Permitted
    std::cout << "Outside accessing public codename (handler1): " << handler1.codename << std::endl;

    // Access to protected member from derived class (Handler): Permitted
    handler1.displayMissionBriefing();

    // Access to private member from derived class (Handler): Not Permitted (compile-time error)
    // handler1.attemptIdentityAccess(); // Error if uncommented

    std::cout << "\n--- Demonstrating Robustness Issue ---" << std::endl;
    std::cout << "Original Handler mission briefing: " << handler1.getMissionBriefingReference() << std::endl;

    // Leveraging the robustness issue: Modifying protected member from main via Handler's public reference
    std::string& briefingRef = handler1.getMissionBriefingReference();
    briefingRef = "MISSION COMPROMISED: New objective - Extract Phoenix immediately!";

    std::cout << "Modified Handler mission briefing via external reference: " << std::endl;
    handler1.displayMissionBriefing(); // Shows the modified briefing

    return 0;
}