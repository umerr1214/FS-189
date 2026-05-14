#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits
#include <random> // For std::random_device, std::mt19937, std::uniform_int_distribution
#include <chrono> // For std::chrono::system_clock (alternative seed)

int main() {
    // For deterministic testing, a fixed seed is used. In a real application,
    // std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
    // would be preferred for true randomness.
    // Sticking to srand(1) for consistency with other generated files' test cases.
    srand(1); // Fixed seed for deterministic testing (secret number will be 84)

    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100;
    const int MAX_ATTEMPTS = 5;

    int secretNumber = rand() % MAX_NUMBER + MIN_NUMBER; // Generates number between 1 and 100
    int guess;
    int attemptsMade = 0;
    bool guessedCorrectly = false;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between " << MIN_NUMBER << " and " << MAX_NUMBER << "." << std::endl;
    std::cout << "You have " << MAX_ATTEMPTS << " attempts to guess it." << std::endl;
    std::cout << std::endl;

    while (attemptsMade < MAX_ATTEMPTS) {
        attemptsMade++;
        std::cout << "Attempt " << attemptsMade << " of " << MAX_ATTEMPTS << ". Guess a number (" << MIN_NUMBER << "-" << MAX_NUMBER << "): ";

        std::cin >> guess;

        // Robust input validation for non-integer input
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            attemptsMade--; // Do not count this as an attempt
            continue; // Ask for input again
        }

        // Robust input validation for number range
        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            std::cout << "Invalid input. Please enter a number between " << MIN_NUMBER << " and " << MAX_NUMBER << "." << std::endl;
            // Clear any extra input on the line, important if user typed e.g. "101abc"
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            attemptsMade--; // Do not count this as an attempt
            continue; // Ask for input again
        }

        // Clear any remaining input on the line after a valid number is read
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << attemptsMade << " attempts." << std::endl;
            guessedCorrectly = true;
            break;
        } else if (guess < secretNumber) {
            std::cout << "Too low!" << std::endl;
        } else { // guess > secretNumber
            std::cout << "Too high!" << std::endl;
        }
    }

    if (!guessedCorrectly) {
        std::cout << "You ran out of attempts! The secret number was " << secretNumber << "." << std::endl;
    }

    return 0;
}