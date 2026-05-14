#include <iostream> // For standard input/output operations
#include <cstdlib>  // For rand() and srand() functions
#include <ctime>    // For time() function (used for seeding random numbers)
#include <limits>   // For std::numeric_limits, used in input validation

int main() {
    // Seed the random number generator.
    // Using a fixed seed (0) for deterministic testing.
    // For a real game, use srand(time(0)); to get a different sequence each run.
    srand(0);

    // Generate a random target number between 1 and 100 (inclusive)
    const int targetNumber = rand() % 100 + 1;
    int userGuess = 0; // Initialize userGuess to a value that won't match targetNumber initially
    int attempts = 0;  // Initialize attempt counter

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have generated a random number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n";

    // Loop until the user guesses the correct number
    while (userGuess != targetNumber) {
        attempts++; // Increment attempt count for each guess

        std::cout << "Attempt " << attempts << ": Enter your guess (1-100): ";
        std::cin >> userGuess;

        // Input validation: Check if input failed (e.g., non-numeric)
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a whole number.\n";
            std::cin.clear(); // Clear the error flags (e.g., failbit)
            // Discard the invalid input from the buffer up to the next newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            attempts--; // Don't count invalid input as an attempt
            continue;   // Ask for input again
        }

        // Input validation: Check if the number is within the valid range
        if (userGuess < 1 || userGuess > 100) {
            std::cout << "Your guess is out of range. Please guess a number between 1 and 100.\n";
            attempts--; // Don't count out-of-range input as a valid attempt
            continue;   // Ask for input again
        }

        // Provide hints based on the guess
        if (userGuess < targetNumber) {
            std::cout << "Too low! Try a higher number.\n";
        } else if (userGuess > targetNumber) {
            std::cout << "Too high! Try a lower number.\n";
        }
        // If userGuess == targetNumber, the loop condition will be false and it will exit.
    }

    // Congratulate the user once the correct number is guessed
    std::cout << "Congratulations! You guessed the number " << targetNumber
              << " in " << attempts << " attempts.\n";

    return 0; // Indicate successful program execution
}