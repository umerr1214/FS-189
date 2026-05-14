#include <iostream>
#include <string>
#include <sstream> // For stringstream
#include <utility> // For std::move

class Movie {
private:
    std::string title;
    std::string director;
    int releaseYear;

public:
    // Constructor with default values for director and releaseYear.
    // Uses initializer lists and pass-by-value-and-move for string parameters for efficiency.
    Movie(std::string title_val, std::string director_val = "Unknown", int releaseYear_val = 2000)
        : title(std::move(title_val)), // Efficiently moves title_val into title
          director(std::move(director_val)), // Efficiently moves director_val into director
          releaseYear(releaseYear_val) {
        // No additional logic needed in the constructor body
    }

    // Getter for title, returns a const reference for efficiency and safety.
    const std::string& getTitle() const {
        return title;
    }

    // Getter for director, returns a const reference for efficiency and safety.
    const std::string& getDirector() const {
        return director;
    }

    // Getter for releaseYear.
    int getReleaseYear() const {
        return releaseYear;
    }

    // Method to display movie information, marked const as it doesn't modify object state.
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
    std::cout << "Movie 2 Details:" << std::endl;
    movie2.display();

    std::cout << std::endl;

    // Test Case 3: Title and director provided, using default releaseYear
    Movie movie3("Pulp Fiction", "Quentin Tarantino");
    std::cout << "Movie 3 Details:" << std::endl;
    movie3.display();

    return 0;
}