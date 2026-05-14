#include <string>
#include <iostream>

class Movie {
public:
    std::string title;
    std::string director;
    int releaseYear;

    Movie(std::string t, std::string d = "Unknown", int ry = 2000)
        : title(t), director(d), releaseYear(ry) {}

    void displayMovie() const {
        std::cout << "Title: " << title
                  << ", Director: " << director
                  << ", Year: " << releaseYear << std::endl;
    }
} // ERROR: Missing semicolon after class definition

int main() {
    Movie movie1("Inception");
    movie1.displayMovie();

    Movie movie2("The Dark Knight", "Christopher Nolan");
    movie2.displayMovie();
    
    Movie movie3("Interstellar", "Christopher Nolan", 2014);
    movie3.displayMovie();

    return 0;
}