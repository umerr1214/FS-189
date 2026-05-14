#include <iostream>
#include <string>
#include <sstream> // For stringstream

class Movie {
private:
    std::string title;
    std::string director;
    int releaseYear;

public:
    // Constructor with default values for director and releaseYear
    Movie(std::string title_val, std::string director_val = "Unknown", int releaseYear_val = 2000)
        : title(std::move(title_val)), director(std::move(director_val)) {
        // Robustness Issue: No validation for releaseYear.
        // Allows arbitrary integer values, including illogical ones (e.g., negative years).
        this->releaseYear = releaseYear_val;
    }

    // Getter for title
    const std::string& getTitle() const {
        return title;
    }

    // Getter for director
    const std::string& getDirector() const {
        return director;
    }

    // Getter for releaseYear
    int getReleaseYear() const {
        return releaseYear;
    }

    // Setter for releaseYear - also lacks validation
    void setReleaseYear(int year) {
        // Robustness Issue: Again, no validation here.
        // A robust class would validate the year (e.g., year > 0 and year <= current_year + margin).
        this->releaseYear = year;
    }

    // Method to display movie information
    void display() const {
        std::cout << "Title: " << title
                  << ", Director: " << director
                  << ", Release Year: " << releaseYear << std::endl;
    }
};

int main() {
    // Test Case 1: All arguments provided
    Movie movie1("Inception", "Christopher Nolan", 2010);
    std::cout << "Movie 1 Details:" << std::endl;
    movie1.display();

    std::cout << std::endl;

    // Test Case 2: Only title provided, using default director and releaseYear
    Movie movie2("Dune");
    std::cout << "Movie 2 Details (before invalid year set):" << std::endl;
    movie2.display();

    // Demonstrate robustness issue: setting an illogical release year
    movie2.setReleaseYear(-500); // Setting a clearly invalid year
    std::cout << "Movie 2 Details (after invalid year set):" << std::endl;
    movie2.display();

    std::cout << std::endl;

    // Test Case 3: Title and director provided, using default releaseYear
    Movie movie3("Pulp Fiction", "Quentin Tarantino");
    std::cout << "Movie 3 Details:" << std::endl;
    movie3.display();

    return 0;
}