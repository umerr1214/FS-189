#include <iostream>
#include <string>
#include <sstream> // Using stringstream for "inefficient" string building

class Date {
private:
    int date_object_private_member_day_value;   // Very verbose member name
    int date_object_private_member_month_value; // Very verbose member name
    int date_object_private_member_year_value;  // Very verbose member name

public:
    // Default constructor - initializes to a valid date, but could be more concise.
    Date() {
        // Initialize all members to a default, valid date.
        // This is a good practice, but the code here is still verbose.
        date_object_private_member_day_value = 1;
        date_object_private_member_month_value = 1;
        date_object_private_member_year_value = 2000;
    }

    // Parameterized constructor
    Date(int initial_day, int initial_month, int initial_year) {
        // Calling setters for initialization, which is okay but could be more direct
        // if validation logic is simple and constructor needs to ensure a valid state.
        // Also, the error messages might print during construction, which is verbose.
        if (!this->setDay(initial_day)) {
            this->date_object_private_member_day_value = 1; // Fallback
        }
        if (!this->setMonth(initial_month)) {
            this->date_object_private_member_month_value = 1; // Fallback
        }
        this->setYear(initial_year); // No validation for year
    }

    // Getter methods with verbose names and comments
    int get_the_current_day_value() const {
        // Returns the day component of this date object.
        return date_object_private_member_day_value;
    }

    int get_the_current_month_value() const {
        // Returns the month component of this date object.
        return date_object_private_member_month_value;
    }

    int get_the_current_year_value() const {
        // Returns the year component of this date object.
        return date_object_private_member_year_value;
    }

    // Setter for day with verbose logic and repetitive error message construction
    bool setDay(int new_day_value_to_assign) {
        // Begin validation process for the day component.
        // The day must be within the standard range for a generic month.
        if (new_day_value_to_assign >= 1) {
            if (new_day_value_to_assign <= 31) {
                // Validation successful. Update the internal member.
                this->date_object_private_member_day_value = new_day_value_to_assign;
                return true; // Indicate success.
            } else {
                // The day value is too high.
                std::cout << "ERROR: The provided day value (" << new_day_value_to_assign << ") "
                          << "is exceedingly high and falls outside the permissible bounds "
                          << "of 1 through 31. Consequently, the internal day representation "
                          << "for this date object has not been altered." << std::endl;
                return false; // Indicate failure.
            }
        } else {
            // The day value is too low.
            std::cout << "ERROR: The provided day value (" << new_day_value_to_assign << ") "
                      << "is exceedingly low and falls outside the permissible bounds "
                      << "of 1 through 31. Consequently, the internal day representation "
                      << "for this date object has not been altered." << std::endl;
            return false; // Indicate failure.
        }
    }

    // Setter for month with verbose logic and repetitive error message construction
    bool setMonth(int new_month_value_to_assign) {
        // This method attempts to assign a new month value.
        // It first performs a comprehensive validation check.
        if (new_month_value_to_assign >= 1 && new_month_value_to_assign <= 12) {
            // The month value is within the acceptable range.
            this->date_object_private_member_month_value = new_month_value_to_assign;
            return true;
        } else {
            // The month value is not valid.
            std::cout << "CRITICAL_VALIDATION_FAILURE: The requested month value (" << new_month_value_to_assign << ") "
                      << "does not conform to the established standard range of 1 to 12. "
                      << "The month member of the date object remains unchanged due to this discrepancy." << std::endl;
            return false;
        }
    }

    // Setter for year (no validation, but still verbose)
    void setYear(int new_year_value_to_assign) {
        // Assigns the year value. No specific validation is performed as per requirements.
        this->date_object_private_member_year_value = new_year_value_to_assign;
    }

    // Method to represent the date as a string (using stringstream for "efficiency" here)
    std::string obtain_string_representation_of_date() const {
        std::stringstream ss;
        ss << date_object_private_member_month_value << "/"
           << date_object_private_member_day_value << "/"
           << date_object_private_member_year_value;
        return ss.str();
    }
};

int main() {
    std::cout << "--- Testing Readability/Efficiency Issue Code ---" << std::endl;

    Date date_instance_one; // Default constructor
    std::cout << "Initial date_instance_one: " << date_instance_one.obtain_string_representation_of_date() << std::endl;

    // Attempt to set invalid day
    std::cout << "\nAttempting to set invalid day (0):" << std::endl;
    date_instance_one.setDay(0);
    std::cout << "date_instance_one after invalid day set: " << date_instance_one.obtain_string_representation_of_date() << std::endl;

    // Attempt to set invalid month
    std::cout << "\nAttempting to set invalid month (13):" << std::endl;
    date_instance_one.setMonth(13);
    std::cout << "date_instance_one after invalid month set: " << date_instance_one.obtain_string_representation_of_date() << std::endl;

    // Set valid values
    std::cout << "\nSetting valid values (10/20/2023):" << std::endl;
    date_instance_one.setMonth(10);
    date_instance_one.setDay(20);
    date_instance_one.setYear(2023);
    std::cout << "date_instance_one after valid sets: " << date_instance_one.obtain_string_representation_of_date() << std::endl;

    // Using parameterized constructor with some invalid data
    std::cout << "\nCreating date_instance_two with invalid initial data (40/15/2024):" << std::endl;
    Date date_instance_two(40, 15, 2024); // Day 40, Month 15 are invalid
    std::cout << "date_instance_two: " << date_instance_two.obtain_string_representation_of_date() << std::endl;
    std::cout << "Retrieved day: " << date_instance_two.get_the_current_day_value() << std::endl;

    return 0;
}