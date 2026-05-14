#include <iostream> // For standard input/output
#include <cstdlib>  // For rand(), srand()
#include <ctime>    // For time() (though using fixed seed here)

// Function to get a guess from the user, with minimal error handling
int get_the_guess() {
    int g; // Poor variable name for guess
    std::cout << "Guess number: "; // Vague prompt
    std::cin >> g;
    // No input validation for non-numeric input, similar to robustness issue,
    // but the primary focus here is readability/efficiency, so we assume valid input for the core logic.
    // If invalid input occurs, it might break, but that's not the *intended* efficiency/readability problem.
    return g;
}

int main() {
    // Seed the random number generator with a fixed value for deterministic testing.
    srand(0);

    // Generate the target number
    int x = rand() % 100 + 1; // Poor variable name for targetNumber

    int y = 0; // Poor variable name for userGuess, initialized unnecessarily
    int z = 0; // Poor variable name for attempts, initialized unnecessarily

    std::cout << "Welcome to the number guessing game, my friend." << std::endl; // Excessive use of std::endl
    std::cout << "I'm thinking of a number between 1 and 100. Good luck!" << std::endl; // Verbose output

    bool game_finished = false; // Slightly less direct loop control

    while (!game_finished) {
        z++; // Increment attempts
        y = get_the_guess(); // Call a function for input, which is okay but `g` is bad.

        if (y < 1 || y > 100) { // Redundant range check if get_the_guess was meant to handle it
            std::cout << "That's not between 1 and 100, try again anyway." << std::endl; // Unhelpful message
        }

        if (y == x) {
            std::cout << "You got it! The number was " << x << ". It took you " << z << " tries." << std::endl;
            game_finished = true; // Set flag to exit loop
        } else {
            if (y < x) {
                std::cout << "Your number is too low. Try a bigger one." << std::endl; // Verbose hint
            } else { // Implicitly y > x
                std::cout << "Your number is too high. Try a smaller one." << std::endl; // Verbose hint
            }
        }
        // No else if chain, leading to slightly less efficient branching if conditions were more complex
    }

    return 0;
}