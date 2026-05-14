#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

int main() {
    std::string sentence;
    char targetChar;
    int count = 0;

    std::cout << "Enter a sentence: ";
    // Semantic Error: std::cin >> targetChar leaves a newline in the buffer,
    // which std::getline then immediately consumes, skipping the sentence input.
    // std::cin.ignore() is needed after std::cin >> targetChar;
    std::getline(std::cin, sentence); // This getline will likely read the leftover newline if targetChar input came first.

    std::cout << "Enter a character to count: ";
    std::cin >> targetChar;
    
    // The order of input is swapped compared to the typical fix,
    // making the problem less obvious but still present if the user enters the character first.
    // To ensure the semantic error, the prompt for character should come BEFORE getline.
    // Let's re-order to make the error more direct.

    // Corrected order for semantic error demonstration:
    // User enters character first, then sentence.
    // The issue arises when std::cin >> char is followed by std::getline without buffer clearing.

    // Let's reset the program structure to clearly show the semantic error.
    // The original prompt order was sentence then char.
    // If I want to show the semantic error with std::cin >> char; followed by std::getline,
    // I MUST prompt for char first.

    // Re-structuring for a clear semantic error:
    std::cout << "Enter a character to count: ";
    std::cin >> targetChar; // Leaves newline in buffer

    // Semantic Error: This getline will read the leftover newline from the previous std::cin >> targetChar,
    // effectively skipping the user's intended sentence input.
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence); // Reads the leftover newline here.
    // The sentence will likely be empty or just a newline.

    for (char c : sentence) {
        if (c == targetChar) {
            count++;
        }
    }

    std::cout << "The character '" << targetChar << "' appears " << count << " times in the sentence." << std::endl;

    return 0;
}