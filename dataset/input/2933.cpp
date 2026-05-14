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
        // LOGICAL ERROR: This method should print the actual messageId, but it prints a generic string.
        std::cout << "Sending " << toString(type) << " notification: Generic integer message" << std::endl;
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
    smsNotifier.send("Hello via SMS!"); // Correct output

    NotificationSystem emailNotifier(EMAIL);
    emailNotifier.send(12345); // Incorrect output due to logical error

    NotificationSystem pushNotifier(PUSH);
    pushNotifier.send("Important update!"); // Correct output
    pushNotifier.send(54321); // Incorrect output

    return 0;
}