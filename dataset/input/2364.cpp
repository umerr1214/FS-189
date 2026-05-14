#include <string>
#include <iostream>

class Movie {
public:
    std::string title;
    std::string director;
    int releaseYear;

    // Semantic Error: Uses overloaded constructors instead of a single constructor
    // with default arguments for director and releaseYear, as specified in the question.

    // Constructor for title only (provides default values)
    Movie(std::string t)
        : title(t), director("Unknown"), releaseYear(2000) {}

    // Constructor for title and director (provides default year)
    Movie(std::string t, std::string d)
        : title(t), director(d), releaseYear(2000) {}

    // Constructor for all fields
    Movie(std::string t, std::string d, int ry)
        : title(t), director(d), releaseYear(ry) {}

    void displayMovie() const {
        std::cout << "Title: " << title
                  << ", Director: " << director
                  << ", Year: " << releaseYear << std::endl;
    }
};

int main() {
    Movie movie1("Inception");
    movie1.displayMovie();

    Movie movie2("The Dark Knight", "Christopher Nolan");
    movie2.displayMovie();
    
    Movie movie3("Interstellar", "Christopher Nolan", 2014);
    movie3.displayMovie();

    return 0;
}