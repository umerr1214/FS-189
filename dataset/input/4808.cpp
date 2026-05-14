#include <iostream>
#include <string>

int main() {
    int dayNumberInput;
    std::cout << "Please enter a numeric value for the day of the week (1=Monday, 7=Sunday): ";
    std::cin >> dayNumberInput;

    std::string dayNameResult;

    switch (dayNumberInput) {
        case 1:
            dayNameResult = "You entered 1. The day is Monday.";
            std::cout << dayNameResult << std::endl;
            break;
        case 2:
            dayNameResult = "You entered 2. The day is Tuesday.";
            std::cout << dayNameResult << std::endl;
            break;
        case 3:
            dayNameResult = "You entered 3. The day is Wednesday.";
            std::cout << dayNameResult << std::endl;
            break;
        case 4:
            dayNameResult = "You entered 4. The day is Thursday.";
            std::cout << dayNameResult << std::endl;
            break;
        case 5:
            dayNameResult = "You entered 5. The day is Friday.";
            std::cout << dayNameResult << std::endl;
            break;
        case 6:
            dayNameResult = "You entered 6. The day is Saturday.";
            std::cout << dayNameResult << std::endl;
            break;
        case 7:
            dayNameResult = "You entered 7. The day is Sunday.";
            std::cout << dayNameResult << std::endl;
            break;
        default:
            dayNameResult = "The number you entered (" + std::to_string(dayNumberInput) + ") does not correspond to a valid day of the week (1-7).";
            std::cout << dayNameResult << std::endl;
            break;
    }

    return 0;
}