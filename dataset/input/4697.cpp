#include <iostream>
#include <vector>
#include <string>
#include <limits>

void displayMenu() {
    std::cout << "\nTask List Menu:\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<std::string> tasks;
    int choice;
    std::string taskDescription;

    do {
        displayMenu();
        std::cin >> choice;

        clearInputBuffer();

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                tasks.push_back(taskDescription);
                std::cout << "Task added!\n";
                break;
            case 2:
                std::cout << "\n--- Your Tasks ---\n";
                if (tasks.empty()) {
                    std::cout << "No tasks yet!\n";
                } else {
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        std::cout << i + 1 << ". " << tasks[i] << "\n";
                    }
                }
                std::cout << "------------------\n";
                break;
            case 3:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice == 3); // LOGICAL ERROR: Loop continues only if choice IS 3, should be choice != 3

    return 0;
}