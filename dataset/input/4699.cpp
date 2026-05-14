#include <iostream>
#include <vector>
#include <string>
#include <limits> // Required for std::numeric_limits

int main() {
    std::vector<std::string> tasks;
    int choice = 0; // Initialize choice to avoid uninitialized warning for the first loop condition

    do {
        std::cout << "\n--- Task List Menu ---\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Robustness Issue: Incomplete input validation for non-integer input.
        // If `std::cin >> choice;` fails (e.g., user types "abc"),
        // `std::cin.fail()` will be true.
        // The code then clears the error state with `std::cin.clear()`,
        // but it critically *fails to discard the bad input* from the buffer
        // using `std::cin.ignore()`.
        // This means the bad input (e.g., "abc") remains in the buffer.
        // In the next iteration of the `do-while` loop, `std::cin >> choice;`
        // will immediately try to read the same bad input, fail again, clear,
        // and fall into the `default` case. This leads to an infinite loop
        // of "Invalid choice. Please try again." messages without allowing
        // further valid input or program termination.
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            // MISSING: std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // This omission is the robustness flaw.
            choice = 0; // Set choice to an invalid value to trigger the default case
        } else {
            // If input was a valid integer, consume the rest of the line (including newline)
            // to prevent issues with subsequent getline calls for task descriptions.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                if (!taskDescription.empty()) {
                    tasks.push_back(taskDescription);
                    std::cout << "Task added.\n";
                } else {
                    std::cout << "Task description cannot be empty.\n";
                }
                break;
            }
            case 2:
                if (tasks.empty()) {
                    std::cout << "No tasks to display.\n";
                } else {
                    std::cout << "\n--- Your Tasks ---\n";
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        std::cout << i + 1 << ". " << tasks[i] << "\n";
                    }
                }
                break;
            case 3:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}