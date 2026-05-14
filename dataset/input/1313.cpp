#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but common for dataset samples

// Base class
class MediaItem {
private:
    std::string title;
    int duration; // in minutes

public:
    MediaItem(std::string title, int duration) : title(title), duration(duration) {}

    std::string getTitle() const { return title; }
    int getDuration() const { return duration; }
};

// Derived class Movie
class Movie : public MediaItem {
private:
    std::string director;

public:
    // Logical Error: director is incorrectly initialized with the string representation of duration.
    // It should be initialized with 'director_name'.
    Movie(std::string title, int duration, std::string director_name)
        : MediaItem(title, duration) {
        this->director = std::to_string(duration); // Incorrect assignment
    }

    std::string getDirector() const { return director; }
};

// Derived class Song
class Song : public MediaItem {
private:
    std::string artist;

public:
    Song(std::string title, int duration, std::string artist_name)
        : MediaItem(title, duration), artist(artist_name) {}

    std::string getArtist() const { return artist; }
};

int main() {
    // Test for Movie's director attribute
    Movie movie("Inception", 148, "Christopher Nolan");
    std::cout << "Movie Title: " << movie.getTitle() << std::endl;
    std::cout << "Movie Duration: " << movie.getDuration() << std::endl;
    std::cout << "Movie Director: " << movie.getDirector() << std::endl; // This will output "148" due to the logical error

    std::cout << "---" << std::endl;

    // Test for Song (this part is implemented correctly)
    Song song("Bohemian Rhapsody", 6, "Queen");
    std::cout << "Song Title: " << song.getTitle() << std::endl;
    std::cout << "Song Duration: " << song.getDuration() << std::endl;
    std::cout << "Song Artist: " << song.getArtist() << std::endl;

    return 0;
}