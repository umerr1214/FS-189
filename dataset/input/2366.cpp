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
    // Readability Issue: Poorly named parameters (t, d, ry).
    // Efficiency Issue: String members (title, director) are not initialized using initializer lists,
    // leading to default construction followed by assignment.
    // Efficiency Issue: String parameters are passed by value, incurring potentially unnecessary copies.
    Movie(std::string t, std::string d = "Unknown", int ry = 2000) {
        this->title = t; // Default construct 'title', then assign 't'
        this->director = d; // Default construct 'director', then assign 'd'
        this->releaseYear = ry;
    }

    // Getter for title
    // Efficiency Issue: Returns std::string by value, potentially creating an unnecessary copy.
    // Readability Issue: Not marked 'const'.
    std::string getTitle() {
        return this->title;
    }

    // Getter for director
    // Efficiency Issue: Returns std::string by value, potentially creating an unnecessary copy.
    // Readability Issue: Not marked 'const'.
    std::string getDirector() {
        return this->director;
    }

    // Getter for releaseYear
    // Readability Issue: Not marked 'const'.
    int getReleaseYear() {
        return this->releaseYear;
    }

    // Method to display movie information
    void display() { // Readability Issue: Not marked 'const'
        std::cout << "Title: " << this->title
                  << ", Director: " << this->director
                  << ", Release Year: " << this->releaseYear << std::endl;
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