#include <iostream>
#include <string>

enum NotificationType { SMS, EMAIL, PUSH };

class NotificationSystem {
private:
    NotificationType type;

public:
    NotificationSystem(NotificationType t) : type(t) {}

    void send(const std::string& message) {
        std::cout << "Sending " << toString(type) << " notification: " << message << std::endl;
    }

    void send(int messageId) {
        std::cout << "Sending " << toString(type) << " notification with ID: " << messageId << std::endl;
    }

    std::string toString(NotificationType t) const {
        switch (t) {
            case SMS: return "SMS";
            case EMAIL: return "EMAIL";
            case PUSH: return "PUSH";
            default: return "UNKNOWN";
        }
    }
};

int main() {
    NotificationSystem smsNotifier(SMS);
    smsNotifier.send("Hello via SMS!");

    NotificationSystem emailNotifier(EMAIL);
    emailNotifier.send(12345);

    // SEMANTIC ERROR: No 'send' method overload exists for a double argument.
    // This will cause a compilation error: "no matching function for call to 'NotificationSystem::send(double)'"
    emailNotifier.send(3.14159); 

    NotificationSystem pushNotifier(PUSH);
    pushNotifier.send("Important update!");

    return 0;
}