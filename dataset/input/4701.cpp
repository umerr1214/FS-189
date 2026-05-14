#include <iostream>
#include <vector>
#include <string>
#include <limits> // Required for std::numeric_limits

// Function to display the menu options to the user
void displayMenu() {
    std::cout << "\n--- Task List Menu ---\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

// Function to get a valid integer choice from the user, handling invalid input robustly
int getChoice() {
    int choice;
    // Loop until a valid integer is entered
    while (!(std::cin >> choice)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear(); // Clear the error flags (e.g., failbit)
        // Discard all characters in the input buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // After a valid integer is read, consume the remaining newline character
    // to prevent it from affecting subsequent `getline` calls.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

// Function to add a new task to the task list
void addTask(std::vector<std::string>& tasks) {
    std::string taskDescription;
    std::cout << "Enter task description: ";
    std::getline(std::cin, taskDescription); // Read the entire line for the task description

    if (!taskDescription.empty()) {
        tasks.push_back(taskDescription);
        std::cout << "Task added successfully.\n";
    } else {
        std::cout << "Task description cannot be empty. Task not added.\n";
    }
}

// Function to display all tasks currently in the list
void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
    } else {
        std::cout << "\n--- Your Tasks ---\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
}

int main() {
    std::vector<std::string> tasks; // Vector to store task descriptions
    int choice; // Variable to store user's menu choice

    // Use a do-while loop to ensure the menu is displayed at least once
    // and continues until the user chooses to exit (choice 3).
    do {
        displayMenu(); // Display the menu options
        choice = getChoice(); // Get a robustly validated choice from the user

        // Perform actions based on the user's choice using a switch statement
        switch (choice) {
            case 1:
                addTask(tasks); // Call function to add a task
                break;
            case 2:
                viewTasks(tasks); // Call function to view tasks
                break;
            case 3:
                std::cout << "Exiting program. Goodbye!\n"; // Exit message
                break;
            default:
                std::cout << "Invalid choice. Please select an option between 1 and 3.\n";
                break;
        }
    } while (choice != 3); // Loop condition: continue as long as choice is not 3

    return 0; // Indicate successful program execution
}