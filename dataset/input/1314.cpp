#include <iostream>
#include <string>

// Base class
class MediaItem {
private:
    std::string title;
    int duration; // in minutes

public:
    // Only a parameterized constructor exists. No default constructor is implicitly generated.
    MediaItem(std::string title, int duration) : title(title), duration(duration) {}

    std::string getTitle() const { return title; }
    int getDuration() const { return duration; }
};

// Derived class Movie
class Movie : public MediaItem {
private:
    std::string director;

public:
    // Semantic Error: The base class constructor 'MediaItem' is not explicitly called
    // in the initializer list. Since 'MediaItem' only has a parameterized constructor
    // (and no default constructor), the compiler cannot implicitly construct the
    // base subobject, leading to a compilation error.
    Movie(std::string title, int duration, std::string director_name) { // Missing ': MediaItem(title, duration)'
        this->director = director_name;
        // The compiler will try to call MediaItem::MediaItem() here, which doesn't exist.
    }

    std::string getDirector() const { return director; }
};

// Derived class Song (correctly implemented, but code won't compile due to Movie error)
class Song : public MediaItem {
private:
    std::string artist;

public:
    Song(std::string title, int duration, std::string artist_name)
        : MediaItem(title, duration), artist(artist_name) {}

    std::string getArtist() const { return artist; }
};

int main() {
    // This program will not compile due to the semantic error in the Movie constructor.
    // Attempting to create a Movie object would trigger the error.
    // Movie movie("Interstellar", 169, "Christopher Nolan"); // This line would cause the compilation error.

    return 0;
}