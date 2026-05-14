#include <iostream>
#include <stdexcept> // For std::runtime_error
#include <exception> // For std::uncaught_exceptions (though not used in final version)

class Logger {
public:
    Logger() {
        std::cout << "Logger created." << std::endl;
    }

    // Robustness issue: Destructor throws an exception.
    // This is problematic because if an exception is already active
    // during stack unwinding (e.g., an exception from main),
    // throwing another from a destructor will call std::terminate.
    // Even without an active exception, throwing from a destructor
    // is generally discouraged as it complicates exception safety guarantees.
    ~Logger() noexcept(false) { // Mark as potentially throwing
        std::cout << "Logger destroyed." << std::endl;
        throw std::runtime_error("Critical error during Logger destruction!");
    }
};

int main() {
    std::cout << "Main started." << std::endl;

    // --- Scenario 1: Destructor throws, caught in main ---
    try {
        Logger problematicLogger; // Logger created
        std::cout << "Inside demonstrate_robustness_issue before destructor call." << std::endl;
    } catch (const std::runtime_error& e) {
        // This block catches the exception thrown by problematicLogger's destructor.
        // No other exception is active, so std::terminate is not called here.
        std::cerr << "Caught exception from destructor: " << e.what() << std::endl;
    }
    std::cout << "Main continuing after catching destructor exception." << std::endl;

    // --- Scenario 2: Destructor throws while another exception is active ---
    // This will trigger std::terminate.
    try {
        Logger anotherLogger; // Logger created
        std::cout << "Throwing an exception from main scope." << std::endl;
        throw std::runtime_error("An exception from main scope."); // This exception is active
    } catch (const std::runtime_error& e) {
        // When 'anotherLogger' goes out of scope here, its destructor is called.
        // Since its destructor also throws AND an exception (e) is already active,
        // C++ standard dictates that std::terminate will be called.
        std::cerr << "Caught main exception: " << e.what() << std::endl;
    }

    std::cout << "Main finished normally (this line might not be reached if terminate was called)." << std::endl;

    return 0;
}