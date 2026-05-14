#include <iostream>
#include <string>
#include <algorithm> // For std::min
#include <functional> // For std::function (not strictly needed for this final version but good practice for test harness)

// Enum for notification types
enum NotificationType { SMS, EMAIL, PUSH };

// Helper to convert enum to string for output
std::string notificationTypeToString(NotificationType type) {
    switch (type) {
        case SMS: return "SMS";
        case EMAIL: return "EMAIL";
        case PUSH: return "PUSH";
        default: return "INVALID_OR_UNINITIALIZED_TYPE"; // Indicates a problem
    }
}

class NotificationSystem {
private:
    NotificationType _type;

public:
    // Constructor 1: Default, initializes to an invalid state to highlight robustness issue
    NotificationSystem() : _type(static_cast<NotificationType>(-1)) {
        // A robust system might throw an exception or log an error here,
        // but this demonstrates a silent initialization to an invalid state.
        std::cout << "NotificationSystem created with an implicitly invalid type." << std::endl;
    }

    // Constructor 2: Accepts NotificationType enum
    NotificationSystem(NotificationType type) : _type(type) {
        std::cout << "NotificationSystem created for " << notificationTypeToString(_type) << " type." << std::endl;
    }

    // Constructor 3: Accepts int, but does NOT validate if it's a valid enum value.
    // This allows creating an object in an invalid state without immediate feedback.
    NotificationSystem(int type_as_int) : _type(static_cast<NotificationType>(type_as_int)) {
        std::cout << "NotificationSystem created for integer type_id " << type_as_int
                  << ". (Internal type: " << notificationTypeToString(_type) << ")" << std::endl;
    }

    // Overloaded send method for std::string content
    void send(const std::string& message) {
        std::cout << "Sending string message: \"" << message << "\" via ";
        switch (_type) {
            case SMS:
                std::cout << "SMS. Length: " << message.length() << "." << std::endl;
                break;
            case EMAIL:
                // Potentially unsafe substr if message is empty, but std::min handles it.
                // Still, a robustness issue could be neglecting edge cases like empty messages.
                std::cout << "EMAIL. Subject: \"" << message.substr(0, std::min((size_t)20, message.length())) << "...\". " << std::endl;
                break;
            case PUSH:
                std::cout << "PUSH. Alert: \"" << message << "\"." << std::endl;
                break;
            default:
                // Robustness issue: No specific error handling or warning for an invalid _type.
                // It just falls into a generic default case, potentially leading to silent failures
                // or unexpected behavior without clear indication to the user.
                std::cout << notificationTypeToString(_type) << ". Message not sent effectively due to invalid type." << std::endl;
                break;
        }
    }

    // Overloaded send method for int content
    void send(int code) {
        std::cout << "Sending integer code: " << code << " via ";
        switch (_type) {
            case SMS:
                std::cout << "SMS. Code: " << code << "." << std::endl;
                break;
            case EMAIL:
                std::cout << "EMAIL. Error code: " << code << "." << std::endl;
                break;
            case PUSH:
                std::cout << "PUSH. Status code: " << code << "." << std::endl;
                break;
            default:
                // Robustness issue: Similar to string, silent failure or generic message for invalid type.
                std::cout << notificationTypeToString(_type) << ". Code not sent effectively due to invalid type." << std::endl;
                break;
        }
    }
};

int main() {
    std::cout << "--- Test Case 1: Valid SMS Notification ---" << std::endl;
    NotificationSystem smsNotifier(SMS);
    smsNotifier.send("Hello via SMS!");
    smsNotifier.send(123);
    std::cout << std::endl;

    std::cout << "--- Test Case 2: Invalid type via int constructor (Robustness Issue) ---" << std::endl;
    NotificationSystem invalidNotifier(99); // 99 is not a valid enum value
    invalidNotifier.send("Critical alert: System overload detected."); // Demonstrates silent failure/generic handling
    invalidNotifier.send(500);
    std::cout << std::endl;

    std::cout << "--- Test Case 3: Default constructed (Robustness Issue) ---" << std::endl;
    NotificationSystem defaultNotifier; // _type initialized to -1
    defaultNotifier.send("Default message from uninitialized system.");
    defaultNotifier.send(0);
    std::cout << std::endl;

    std::cout << "--- Test Case 4: Valid Email Notification ---" << std::endl;
    NotificationSystem emailNotifier(EMAIL);
    emailNotifier.send("Important Meeting Reminder: Don't forget the daily stand-up at 9 AM.");
    emailNotifier.send(404);
    std::cout << std::endl;

    std::cout << "--- Test Case 5: Valid PUSH Notification ---" << std::endl;
    NotificationSystem pushNotifier(PUSH);
    pushNotifier.send("New message received!");
    pushNotifier.send(200);
    std::cout << std::endl;

    return 0;
}