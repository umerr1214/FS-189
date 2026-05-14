#include <iostream>
#include <cstdlib> // For rand(), srand()
#include <ctime>   // For time()
#include <limits>  // For std::numeric_limits

int main() {
    // Seed the random number generator with current time
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Choose a random number between 1 and 100 (inclusive)
    int secretNumber = std::rand() % 100 + 1;
    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have chosen a number between 1 and 100." << std::endl;

    // Use a do-while loop for the game logic
    do {
        std::cout << "Enter your guess (1-100): ";
        
        // Robust input validation loop
        while (!(std::cin >> guess)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear(); // Clear the error flags
            // Discard invalid input up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // Discard any remaining characters on the line after a valid number
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Check if the guess is within the valid range
        if (guess < 1 || guess > 100) {
            std::cout << "Your guess is out of range. Please guess a number between 1 and 100." << std::endl;
            continue; // Skip the rest of the loop and prompt for a new guess
        }

        attempts++; // Increment attempt counter for valid guesses

        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts." << std::endl;
        }
    } while (guess != secretNumber); // Continue loop until the correct number is guessed

    return 0;
}