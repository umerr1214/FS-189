#include <iostream>
#include <string>

class MediaItem {
private:
    std::string title;
    int duration;
public:
    // Readability/Efficiency Issue: Passing string by value.
    // This causes an unnecessary copy of the string argument.
    MediaItem(std::string t, int d) : title(t), duration(d) {
        // No validation, focusing on other issues for this category.
    }

    // Readability/Efficiency Issue: Getters are not const-qualified.
    // This prevents them from being called on const objects and is generally bad practice.
    std::string getTitle() { return title; }
    int getDuration() { return duration; }

    ~MediaItem() {
        // Readability/Efficiency Issue: Using std::endl instead of '\n'.
        // std::endl flushes the buffer, which can be less efficient than '\n'.
        std::cout << "MediaItem destructor for '" << title << "' called." << std::endl;
    }
};

class Movie : public MediaItem {
private:
    std::string director;
public:
    // Readability/Efficiency Issue: Passing string by value.
    Movie(std::string t, int d, std::string dir)
        : MediaItem(t, d) // Base constructor is correctly called via initializer list
    {
        // Readability/Efficiency Issue: Initializing member via assignment in the constructor body.
        // It's generally more efficient and readable to use the initializer list for all members.
        this->director = dir; 
    }

    // Readability/Efficiency Issue: Getter is not const-qualified.
    std::string getDirector() { return director; }

    ~Movie() {
        // Readability/Efficiency Issue: Using std::endl instead of '\n'.
        std::cout << "Movie destructor for '" << getTitle() << "' called." << std::endl;
    }
};

class Song : public MediaItem {
private:
    std::string artist;
public:
    // Readability/Efficiency Issue: Passing string by value.
    Song(std::string t, int d, std::string art)
        : MediaItem(t, d) // Base constructor is correctly called via initializer list
    {
        // Readability/Efficiency Issue: Initializing member via assignment in the constructor body.
        // It's generally more efficient and readable to use the initializer list for all members.
        this->artist = art;
    }

    // Readability/Efficiency Issue: Getter is not const-qualified.
    std::string getArtist() { return artist; }

    ~Song() {
        // Readability/Efficiency Issue: Using std::endl instead of '\n'.
        std::cout << "Song destructor for '" << getTitle() << "' called." << std::endl;
    }
};

int main() {
    // Readability/Efficiency Issue: Excessive use of std::endl.
    std::cout << "--- Testing MediaItem Hierarchy (Readability/Efficiency Issue) ---" << std::endl << std::endl;

    Movie movie1("Interstellar", 169, "Christopher Nolan");
    std::cout << "Movie 1 Details:" << std::endl;
    std::cout << "  Title: " << movie1.getTitle() << std::endl;
    std::cout << "  Duration: " << movie1.getDuration() << " minutes" << std::endl;
    std::cout << "  Director: " << movie1.getDirector() << std::endl << std::endl;

    Song song1("Stairway to Heaven", 482, "Led Zeppelin");
    std::cout << "Song 1 Details:" << std::endl;
    std::cout << "  Title: " << song1.getTitle() << std::endl;
    std::cout << "  Duration: " << song1.getDuration() << " seconds" << std::endl;
    std::cout << "  Artist: " << song1.getArtist() << std::endl << std::endl;

    Movie movie2("The Matrix", 136, "The Wachowskis");
    std::cout << "Movie 2 Details:" << std::endl;
    std::cout << "  Title: " << movie2.getTitle() << std::endl;
    std::cout << "  Duration: " << movie2.getDuration() << " minutes" << std::endl;
    std::cout << "  Director: " << movie2.getDirector() << std::endl << std::endl;

    Song song2("Hotel California", 390, "Eagles");
    std::cout << "Song 2 Details:" << std::endl;
    std::cout << "  Title: " << song2.getTitle() << std::endl;
    std::cout << "  Duration: " << song2.getDuration() << " seconds" << std::endl;
    std::cout << "  Artist: " << song2.getArtist() << std::endl << std::endl;

    return 0;
}