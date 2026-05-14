#include <iostream>
#include <string>

// Renamed main to user_main for testing purposes
int user_main() {
    int h; // Readability Issue: Non-descriptive variable name
    // Input is provided by the test driver, no prompt needed.
    std::cin >> h;

    if (h <= 0) { // Basic validation, but overall code has readability/efficiency issues
        return 0;
    }

    int current_width = 1; // Readability Issue: Another non-descriptive variable name
    while (current_width <= h) { // Readability Issue: Less common while loop structure for iteration
        std::string row_content = "";
        int stars_to_add = 0; // Readability Issue: Another non-descriptive variable name
        while (stars_to_add < current_width) { // Readability Issue: Less common while loop structure
            row_content += "*"; // Efficiency Issue: Inefficient string building (repeated reallocations)
            stars_to_add++;
        }
        std::cout << row_content << std::endl; // Efficiency Issue: std::endl flushes buffer, less efficient than '\n'
        current_width++;
    }

    return 0;
}