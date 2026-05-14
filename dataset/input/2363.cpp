#include <string>
#include <iostream>

class Movie {
public:
    std::string title;
    std::string director;
    int releaseYear;

    // Logical Error: Default releaseYear is 1900 instead of 2000 as per example
    Movie(std::string t, std::string d = "Unknown", int ry = 1900) // Should be 2000
        : title(t), director(d), releaseYear(ry) {}

    void displayMovie() const {
        std::cout << "Title: " << title
                  << ", Director: " << director
                  << ", Year: " << releaseYear << std::endl;
    }
};

int main() {
    Movie movie1("Inception"); // Expected Year: 2000, Actual: 1900
    Movie movie2("The Dark Knight", "Christopher Nolan"); // Expected Year: 2000, Actual: 1900
    Movie movie3("Interstellar", "Christopher Nolan", 2014); // Correct
    Movie movie4("Dune", "Denis Villeneuve", 2021); // Correct

    movie1.displayMovie();
    movie2.displayMovie();
    movie3.displayMovie();
    movie4.displayMovie();

    return 0;
}