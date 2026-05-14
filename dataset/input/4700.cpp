#include <iostream>
#include <vector>
#include <string>
#include <limits> // For std::numeric_limits

int main() {
    std::vector<std::string> tsks; // Poor variable name: 'tasks' would be clearer
    int ch = 0; // Poor variable name: 'choice' would be clearer
    std::string tsk_desc; // Poor variable name: 'taskDescription' would be clearer

    do {
        std::cout << "\n--- M E N U ---\n"; // Bad formatting, lacks clarity
        std::cout << "1. Add\n"; // Abbreviated option
        std::cout << "2. View\n"; // Abbreviated option
        std::cout << "3. Exit\n";
        std::cout << "Enter option: "; // Informal prompt
        std::cin >> ch;

        // Basic input robustness is present, but the focus of this file is readability/efficiency
        if (std::cin.fail()) {
            std::cout << "Bad input. Try again.\n"; // Informal error message
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ch = 0; // Reset choice to trigger default-like behavior
            continue; // Continue to next loop iteration
        }

        // Long if-else if chain instead of a more readable switch statement or separate functions
        if (ch == 1) {
            std::cout << "What to add? "; // Informal prompt
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consumes newline
            std::getline(std::cin, tsk_desc);
            if (!tsk_desc.empty()) {
                tsks.push_back(tsk_desc);
                std::cout << "Added.\n"; // Abbreviated confirmation
            } else {
                std::cout << "Empty task not allowed.\n"; // Informal error
            }
        } else if (ch == 2) {
            if (tsks.empty()) {
                std::cout << "No items.\n"; // Abbreviated message
            } else {
                std::cout << "\n--- I T E M S ---\n"; // Bad formatting, lacks clarity
                for (size_t i = 0; i < tsks.size(); ++i) {
                    std::cout << i + 1 << ". " << tsks[i] << "\n";
                }
            }
        } else if (ch == 3) {
            std::cout << "Bye!\n"; // Informal exit message
        } else {
            std::cout << "Invalid option. Select 1-3.\n"; // Informal error
        }
    } while (ch != 3);

    return 0;
}