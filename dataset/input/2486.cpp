#include <iostream>
#include <string>
#include <vector> // Unnecessary include for this problem, but adds to "bloat"

using namespace std; // This is okay, but then inconsistently using std:: prefix adds to readability issues.

class SecretAgent {
public:
    string agentCodename; // Renamed for verbosity

protected:
    string agentMissionBriefing; // Renamed for verbosity

private:
    string agentTrueIdentity; // Renamed for verbosity

public:
    // Overly verbose constructor with redundant assignments instead of initializer list
    SecretAgent(const string& initialCodename, const string& initialIdentity, const string& initialBriefing) {
        string tempCodename = initialCodename;
        this->agentCodename = tempCodename;

        string tempIdentity = initialIdentity;
        this->agentTrueIdentity = tempIdentity;

        string tempBriefing = initialBriefing;
        this->agentMissionBriefing = tempBriefing;

        std::cout << "SecretAgent object constructed with codename: " << this->agentCodename << std::endl; // Inconsistent std::cout
    }

    // Redundant getter for codename, even though it's public
    string retrieveCodename() const {
        std::cout << "A public method called to retrieve the public codename." << std::endl;
        return agentCodename;
    }

    // A getter for private identity, but prints to console and returns, leading to verbose output
    string acquireTrueIdentityInformation() const {
        string identityInfo = "Information about true identity: ";
        identityInfo += this->agentTrueIdentity;
        cout << "Accessing private data via public method: " << identityInfo << endl; // Inconsistent cout
        return identityInfo;
    }
};

class Handler : public SecretAgent {
public:
    Handler(const string& handlerName, const string& handlerIdentity, const string& handlerBriefing)
        : SecretAgent(handlerName, handlerIdentity, handlerBriefing) {
        cout << "Handler object constructed for agent: " << this->agentCodename << endl; // Inconsistent cout
    }

    // Overly verbose method to display mission briefing with unnecessary copies and redundant statements
    void processAndDisplayMissionBriefing() const {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Handler's specific mission briefing processing routine initiated." << std::endl;
        string currentBriefingContent = this->agentMissionBriefing; // Unnecessary copy
        if (!currentBriefingContent.empty()) {
            cout << "The current mission briefing is: "; // Inconsistent cout
            cout << currentBriefingContent; // Redundant statement
            cout << "." << endl; // Inconsistent cout
        } else {
            std::cout << "No mission briefing content available at this time." << std::endl;
        }
        std::cout << "Handler's specific mission briefing processing routine concluded." << std::endl;
        std::cout << "---------------------------------------" << std::endl;
    }

    // Method to try and access private member (would fail compilation if uncommented)
    /*
    void attemptIllegalIdentityAccess() {
        cout << "Attempting to access private true identity from Handler: " << agentTrueIdentity << endl;
    }
    */
};

int main() {
    // Redundant object creation for demonstration, impacting efficiency
    SecretAgent primaryAgent("Falcon", "Alice Johnson", "Primary objective: Locate target asset.");
    SecretAgent secondaryAgent = primaryAgent; // Unnecessary copy

    Handler missionHandler("Eagle", "Bob Williams", "Support primary agent with intel.");
    Handler backupHandler = missionHandler; // Unnecessary copy

    cout << "\n--- Demonstrating Access Levels (Readability Issue Version) ---" << endl;

    cout << "\nAccessing Public Members from Outside (main function):" << endl;
    std::cout << "Primary Agent's Codename (direct access): " << primaryAgent.agentCodename << std::endl;
    primaryAgent.agentCodename = "Vulture"; // Direct modification
    cout << "Primary Agent's Codename (after modification): " << primaryAgent.agentCodename << endl;
    std::cout << "Secondary Agent's Codename (using redundant getter): " << secondaryAgent.retrieveCodename() << std::endl;


    cout << "\nAttempting to Access Private Members from Outside (main function):" << endl;
    // std::cout << primaryAgent.agentTrueIdentity << std::endl; // This would cause a compilation error.
    std::cout << "Direct access to private 'agentTrueIdentity' is restricted. Cannot compile." << std::endl;
    // Calling method that prints itself, then printing its return value, creating redundant output
    std::cout << "Accessing private 'agentTrueIdentity' via public method: " << primaryAgent.acquireTrueIdentityInformation() << std::endl;

    cout << "\nAttempting to Access Protected Members from Outside (main function):" << endl;
    // std::cout << primaryAgent.agentMissionBriefing << std::endl; // This would cause a compilation error.
    std::cout << "Direct access to protected 'agentMissionBriefing' is restricted. Cannot compile." << std::endl;

    cout << "\nAccessing Members from Derived Class (Handler):" << endl;
    std::cout << "Mission Handler's Codename (inherited public): " << missionHandler.agentCodename << std::endl;
    missionHandler.processAndDisplayMissionBriefing(); // Accessing protected missionBriefing

    cout << "\nAttempting to Access Private Members from Derived Class (Handler):" << endl;
    // missionHandler.attemptIllegalIdentityAccess(); // This would cause a compilation error if uncommented.
    std::cout << "Handler cannot directly access inherited private 'agentTrueIdentity'. Cannot compile." << std::endl;

    cout << "\n--- End of Demonstration ---" << endl;

    return 0;
}