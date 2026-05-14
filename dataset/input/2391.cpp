#include <iostream> // Required for std::cout

// The Logger class prints messages during construction and destruction.
class Logger {
public:
    // Constructor: Called when a Logger object is created.
    Logger() {
        std::cout << "Logger created." << '\n'; // Use '\n' for efficiency
    }

    // Destructor: Called when a Logger object is destroyed (goes out of scope).
    ~Logger() {
        std::cout << "Logger destroyed." << '\n'; // Use '\n' for efficiency
    }
};

// The main function demonstrates the usage of the Logger class.
int main() {
    std::cout << "Entering main function." << '\n';

    // Create a Logger object. Its constructor will be called here.
    Logger myLogger;

    std::cout << "Logger object 'myLogger' is active." << '\n';

    // Demonstrate another Logger object within a nested scope.
    // This shows that objects are destroyed when they go out of scope.
    {
        std::cout << "\nEntering nested scope." << '\n';
        Logger anotherLogger; // Constructor called for 'anotherLogger'
        std::cout << "Logger object 'anotherLogger' is active." << '\n';
    } // 'anotherLogger' goes out of scope here, its destructor is called.
    std::cout << "Exited nested scope. 'anotherLogger' destroyed." << '\n';

    std::cout << "\nExiting main function." << '\n';
    // 'myLogger' goes out of scope here, its destructor is called.
    return 0;
}