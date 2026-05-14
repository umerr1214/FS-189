#include <iostream>
#include <cstdlib> // For rand(), srand()
#include <ctime>   // For time()
#include <limits>  // For numeric_limits

int main() {
    // Seed the random number generator
    // Using a fixed seed (0) for deterministic testing.
    // In a real game, you'd use srand(time(0));
    srand(0);

    // Generate a random number between 1 and 100
    int targetNumber = rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have generated a random number between 1 and 100.\n";
    std::cout << "Try to guess it!\n";

    while (true) {
        attempts++;
        std::cout << "Attempt " << attempts << ": Enter your guess: ";
        std::cin >> userGuess;

        // --- ROBUSTNESS ISSUE HERE ---
        // If non-numeric input is entered, std::cin.fail() will be true.
        // The error state is set, and the input buffer is not cleared.
        // Subsequent reads will also fail, leading to an infinite loop
        // of "Enter your guess: " prompts without accepting new input.
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            // This is the robustness issue: not clearing the failbit
            // and not ignoring the bad input in the buffer.
            // A robust solution would include:
            // std::cin.clear(); // Clear the error flags
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            // And then continue the loop.
            // Without it, the program gets stuck.
        } else if (userGuess < 1 || userGuess > 100) {
            // This is also a minor robustness issue:
            // While it's a number, it's out of the expected range,
            // but the game proceeds without specific guidance on the range.
            std::cout << "Your guess is out of the 1-100 range. Try again.\n";
        } else if (userGuess < targetNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (userGuess > targetNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number " << targetNumber
                      << " in " << attempts << " attempts.\n";
            break; // Exit the loop when the guess is correct
        }
    }

    return 0;
}