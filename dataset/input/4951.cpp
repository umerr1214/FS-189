#include <iostream>
#include <cstdlib> // For srand, rand
#include <ctime>   // For time (though we'll use a fixed seed for testing)

int main() {
    // Seed the random number generator. Using a fixed seed for deterministic testing.
    srand(1); // Secret number will be 84 with this seed on many systems

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    const int MAX_ATTEMPTS = 5;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100." << std::endl;
    std::cout << "You have " << MAX_ATTEMPTS << " attempts to guess it." << std::endl;
    std::cout << std::endl;

    while (attempts < MAX_ATTEMPTS) {
        attempts++;
        std::cout << "Attempt " << attempts << " of " << MAX_ATTEMPTS << ". Guess a number (1-100): ";
        std::cin >> guess;

        // --- ROBUSTNESS ISSUE: No input validation for non-integers or out-of-range numbers ---
        // If user enters non-integer, cin.fail() will be true.
        // The program does not clear the error state or ignore bad input.
        // This will cause an infinite loop or other undefined behavior
        // as cin will continuously fail on subsequent reads, or use a default value (0).
        // Also, no explicit check if 'guess' is between 1 and 100.

        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts." << std::endl;
            break;
        } else if (guess < secretNumber) {
            std::cout << "Too low!" << std::endl;
        } else { // guess > secretNumber
            std::cout << "Too high!" << std::endl;
        }

        if (attempts == MAX_ATTEMPTS && guess != secretNumber) {
            std::cout << "You ran out of attempts! The secret number was " << secretNumber << "." << std::endl;
        }
    }

    return 0;
}