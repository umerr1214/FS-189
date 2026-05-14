#include <iostream>
#include <string>
#include <algorithm> // For std::min

enum NotificationType { SMS, EMAIL, PUSH };

class NotificationSystem {
private:
    NotificationType myType; // Less descriptive name

public:
    // Constructor 1
    NotificationSystem(NotificationType type) {
        myType = type;
        std::cout << "Notifier created with type: ";
        if (myType == SMS) { // Inefficient if-else if chain in constructor
            std::cout << "SMS" << std::endl; // Excessive std::endl
        } else if (myType == EMAIL) {
            std::cout << "EMAIL" << std::endl;
        } else if (myType == PUSH) {
            std::cout << "PUSH" << std::endl;
        } else {
            std::cout << "UNKNOWN" << std::endl;
        }
    }

    // Constructor 2: Overloaded to accept int, casting it to enum
    NotificationSystem(int type_val) {
        myType = static_cast<NotificationType>(type_val);
        std::cout << "Notifier created with int type value: " << type_val << std::endl;
    }

    // Overloaded send method for std::string content
    void send(const std::string& msg) { // Short variable name
        std::string prefix = "Sending a message: "; // Redundant string creation
        std::cout << prefix << "\"" << msg << "\" via ";
        if (myType == SMS) { // Inefficient if-else if chain
            std::cout << "SMS. Content length is " + std::to_string(msg.length()) + "." << std::endl; // Inefficient string concatenation
        } else if (myType == EMAIL) {
            std::cout << "EMAIL. Subject preview: " + msg.substr(0, std::min((size_t)25, msg.length())) + "..." << std::endl; // Inefficient string concatenation
        } else if (myType == PUSH) {
            std::cout << "PUSH. Alert text: " + msg + "." << std::endl; // Inefficient string concatenation
        } else {
            std::cout << "Unknown notification type. Message not sent." << std::endl;
        }
        std::cout << "--- End of string send operation ---" << std::endl; // More std::endl
    }

    // Overloaded send method for int content
    void send(int num) { // Short variable name
        std::cout << "Sending an integer: " << num << " via ";
        if (myType == SMS) { // Inefficient if-else if chain
            std::cout << "SMS. Numeric code: " << num << "." << std::endl;
        } else if (myType == EMAIL) {
            std::cout << "EMAIL. Error code: " << num << "." << std::endl;
        } else if (myType == PUSH) {
            std::cout << "PUSH. Status update: " << num << "." << std::endl;
        } else {
            std::cout << "Unknown notification type. Integer not sent." << std::endl;
        }
        std::cout << "--- End of int send operation ---" << std::endl; // More std::endl
    }
};

int main() {
    std::cout << "Starting notification tests." << std::endl << std::endl;

    NotificationSystem n1(SMS); // Less descriptive object name
    n1.send("Test SMS message number one.");
    n1.send(101);
    std::cout << std::endl;

    NotificationSystem n2(EMAIL);
    n2.send("Hello, this is an important email to read right now!");
    n2.send(202);
    std::cout << std::endl;

    NotificationSystem n3(PUSH);
    n3.send("New update available for your application.");
    n3.send(303);
    std::cout << std::endl;

    NotificationSystem n4(static_cast<NotificationType>(5)); // Invalid type to show default path
    n4.send("This message should not be sent effectively.");
    n4.send(500);
    std::cout << std::endl;

    std::cout << "All notification tests completed." << std::endl;

    return 0;
}