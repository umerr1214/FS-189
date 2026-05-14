#include <iostream>
#include <cstdlib> // For srand, rand
#include <ctime>   // For time (though we'll use a fixed seed for testing)
#include <limits>  // For std::numeric_limits

int main() {
    // Seed the random number generator. Using a fixed seed for deterministic testing.
    srand(1); // Secret number will be 84 with this seed on many systems

    int s_num = rand() % 100 + 1; // Cryptic variable name for secret number
    int u_guess; // Cryptic variable name for user guess
    int i = 0; // Cryptic variable name for current attempt counter

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100." << std::endl;
    std::cout << "You have 5 attempts to guess it." << std::endl; // Magic number 5
    std::cout << std::endl;

    while (i < 5) { // Magic number 5
        i++;
        std::cout << "Attempt " << i << " of " << 5 << ". Guess a number (1-100): "; // Magic number 5
        std::cin >> u_guess;

        // Basic input validation to prevent crash on non-integer, but not robust or clearly structured.
        if (std::cin.fail()) {
            std::cout << "Invalid input! Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i--; // Decrement attempt count if input was invalid, so it doesn't count as a real attempt.
                 // This is a common fix but makes the flow a bit less straightforward and readable.
            continue;
        }
        
        // No explicit range validation message for numbers outside 1-100, just uses higher/lower logic.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any extra input on the line

        if (u_guess == s_num) {
            std::cout << "Congratulations! You guessed the number " << s_num << " in " << i << " attempts." << std::endl;
            break;
        } else if (u_guess < s_num) {
            std::cout << "Too low!" << std::endl;
        } else { // u_guess > s_num
            std::cout << "Too high!" << std::endl;
        }

        if (i == 5 && u_guess != s_num) { // Magic number 5
            std::cout << "You ran out of attempts! The secret number was " << s_num << "." << std::endl;
        }
    }

    return 0;
}