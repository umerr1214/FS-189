#include <iostream>
#include <string>

// Base class
class MediaItem {
private:
    std::string title;
    int duration; // in minutes

public:
    MediaItem(std::string title, int duration) : title(title), duration(duration) {}

    std::string getTitle() const { return title; }
    int getDuration() const { return duration; }
} // Syntax Error: Missing semicolon here

// Derived class Movie
class Movie : public MediaItem {
private:
    std::string director;

public:
    Movie(std::string title, int duration, std::string director_name)
        : MediaItem(title, duration), director(director_name) {}

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
    // This program will not compile due to the syntax error.
    // Therefore, no runtime test cases can be executed.
    // The main function provides the complete program structure.
    return 0;
}