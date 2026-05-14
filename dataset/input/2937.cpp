#include <iostream>
#include <string>
#include <algorithm> // For std::min

// Enum for notification types
enum NotificationType { SMS, EMAIL, PUSH };

// Helper function to convert NotificationType enum to string for better readability in output
std::string notificationTypeToString(NotificationType type) {
    switch (type) {
        case SMS: return "SMS";
        case EMAIL: return "EMAIL";
        case PUSH: return "PUSH";
        default: return "UNKNOWN_TYPE"; // Good practice for robustness even in correct version
    }
}

class NotificationSystem {
private:
    NotificationType _notificationType;

public:
    // Overloaded constructor 1: Accepts NotificationType enum directly
    NotificationSystem(NotificationType type) : _notificationType(type) {
        std::cout << "NotificationSystem initialized for " << notificationTypeToString(_notificationType) << " notifications.\n";
    }

    // Overloaded constructor 2: Accepts an int, validates it before setting the type.
    // If invalid, sets to a default or throws an error (here, default to SMS for simplicity or handle error).
    NotificationSystem(int type_as_int) {
        if (type_as_int >= SMS && type_as_int <= PUSH) {
            _notificationType = static_cast<NotificationType>(type_as_int);
            std::cout << "NotificationSystem initialized for " << notificationTypeToString(_notificationType)
                      << " notifications from integer ID " << type_as_int << ".\n";
        } else {
            // Robust error handling: set to a default valid type or throw an exception.
            // For this problem, setting to SMS (a valid default) is reasonable.
            _notificationType = SMS;
            std::cerr << "Warning: Invalid notification type ID (" << type_as_int
                      << ") provided. Defaulting to SMS notifications.\n";
            std::cout << "NotificationSystem initialized for default SMS notifications.\n";
        }
    }

    // Overloaded send method for std::string content
    void send(const std::string& message) const { // const correctness
        std::cout << "Sending message: \"" << message << "\" via ";
        switch (_notificationType) { // Efficient switch statement
            case SMS:
                std::cout << "SMS. (Length: " << message.length() << ")\n";
                break;
            case EMAIL:
                // Efficient output, clear subject preview
                std::cout << "EMAIL. (Subject: \"" << message.substr(0, std::min((size_t)50, message.length())) << "...\")\n";
                break;
            case PUSH:
                std::cout << "PUSH. (Alert: \"" << message << "\")\n";
                break;
            default: // Should ideally not be reached if constructors validate, but good for safety
                std::cerr << "Error: Attempted to send with an UNKNOWN_TYPE. Message not sent.\n";
                break;
        }
    }

    // Overloaded send method for int content
    void send(int code) const { // const correctness
        std::cout << "Sending code: " << code << " via ";
        switch (_notificationType) { // Efficient switch statement
            case SMS:
                std::cout << "SMS. (Code: " << code << ")\n";
                break;
            case EMAIL:
                std::cout << "EMAIL. (Error code: " << code << ")\n";
                break;
            case PUSH:
                std::cout << "PUSH. (Status: " << code << ")\n";
                break;
            default: // Should ideally not be reached
                std::cerr << "Error: Attempted to send with an UNKNOWN_TYPE. Code not sent.\n";
                break;
        }
    }
};

int main() {
    std::cout << "--- Test Case 1: SMS Notification (enum constructor) ---\n";
    NotificationSystem smsNotifier(SMS);
    smsNotifier.send("Hello from the C++ NotificationSystem!");
    smsNotifier.send(101);
    std::cout << "\n";

    std::cout << "--- Test Case 2: EMAIL Notification (enum constructor) ---\n";
    NotificationSystem emailNotifier(EMAIL);
    emailNotifier.send("Important update: Your monthly report is ready.");
    emailNotifier.send(200);
    std::cout << "\n";

    std::cout << "--- Test Case 3: PUSH Notification (enum constructor) ---\n";
    NotificationSystem pushNotifier(PUSH);
    pushNotifier.send("Your order has been shipped!");
    pushNotifier.send(202);
    std::cout << "\n";

    std::cout << "--- Test Case 4: SMS Notification (int constructor, valid) ---\n";
    NotificationSystem smsNotifierInt(0); // SMS is 0
    smsNotifierInt.send("SMS from integer constructor.");
    smsNotifierInt.send(100);
    std::cout << "\n";

    std::cout << "--- Test Case 5: EMAIL Notification (int constructor, valid) ---\n";
    NotificationSystem emailNotifierInt(1); // EMAIL is 1
    emailNotifierInt.send("Email from integer constructor.");
    emailNotifierInt.send(201);
    std::cout << "\n";

    std::cout << "--- Test Case 6: Invalid Type (int constructor, handled gracefully) ---\n";
    NotificationSystem invalidTypeNotifier(99); // Invalid integer ID
    invalidTypeNotifier.send("This message should default to SMS.");
    invalidTypeNotifier.send(500);
    std::cout << "\n";

    return 0;
}