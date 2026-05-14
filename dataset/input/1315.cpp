#include <iostream>
#include <string>
#include <stdexcept> // Included for completeness, but not utilized for validation in this version

class MediaItem {
private:
    std::string title;
    int duration; // in minutes/seconds
public:
    MediaItem(std::string t, int d) : title(t), duration(d) {
        // Robustness Issue: No input validation here.
        // Allows creation of objects with empty titles or non-positive durations.
    }

    // Robustness Issue: Getters are not const-qualified.
    std::string getTitle() { return title; }
    int getDuration() { return duration; }

    // Robustness Issue: Missing virtual destructor.
    // This can lead to undefined behavior if derived objects are deleted via a base class pointer.
    ~MediaItem() {
        std::cout << "MediaItem destructor for '" << title << "' called.\n";
    }
};

class Movie : public MediaItem {
private:
    std::string director;
public:
    Movie(std::string t, int d, std::string dir)
        : MediaItem(t, d), director(dir) {
        // Robustness Issue: No input validation for director.
    }

    // Robustness Issue: Getter is not const-qualified.
    std::string getDirector() { return director; }

    ~Movie() {
        std::cout << "Movie destructor for '" << getTitle() << "' called.\n";
    }
};

class Song : public MediaItem {
private:
    std::string artist;
public:
    Song(std::string t, int d, std::string art)
        : MediaItem(t, d), artist(art) {
        // Robustness Issue: No input validation for artist.
    }

    // Robustness Issue: Getter is not const-qualified.
    std::string getArtist() { return artist; }

    ~Song() {
        std::cout << "Song destructor for '" << getTitle() << "' called.\n";
    }
};

int main() {
    std::cout << "--- Testing MediaItem Hierarchy (Robustness Issue) ---\n\n";

    // Valid cases
    Movie movie1("Inception", 148, "Christopher Nolan");
    std::cout << "Movie 1 Details:\n";
    std::cout << "  Title: " << movie1.getTitle() << "\n";
    std::cout << "  Duration: " << movie1.getDuration() << " minutes\n";
    std::cout << "  Director: " << movie1.getDirector() << "\n\n";

    Song song1("Bohemian Rhapsody", 354, "Queen");
    std::cout << "Song 1 Details:\n";
    std::cout << "  Title: " << song1.getTitle() << "\n";
    std::cout << "  Duration: " << song1.getDuration() << " seconds\n";
    std::cout << "  Artist: " << song1.getArtist() << "\n\n";

    // Robustness issue demonstration: Invalid input not handled
    std::cout << "--- Testing Invalid Inputs (Robustness Issue) ---\n\n";

    // Creating a movie with empty title, negative duration, and empty director
    Movie movie2("", -10, ""); 
    std::cout << "Movie 2 (Invalid) Details:\n";
    std::cout << "  Title: '" << movie2.getTitle() << "'\n"; // Prints ''
    std::cout << "  Duration: " << movie2.getDuration() << " minutes\n"; // Prints -10
    std::cout << "  Director: '" << movie2.getDirector() << "'\n\n"; // Prints ''

    // Creating a song with title containing only spaces, zero duration, and artist with spaces
    Song song2("   ", 0, "   "); 
    std::cout << "Song 2 (Invalid) Details:\n";
    std::cout << "  Title: '" << song2.getTitle() << "'\n"; // Prints '   '
    std::cout << "  Duration: " << song2.getDuration() << " seconds\n"; // Prints 0
    std::cout << "  Artist: '" << song2.getArtist() << "'\n\n"; // Prints '   '

    // Note: The lack of a virtual destructor is a design flaw for base classes intended for
    // polymorphism. While not directly causing an issue with stack-allocated objects,
    // it would be problematic with `MediaItem* item = new Movie(...)` followed by `delete item;`.

    return 0;
}