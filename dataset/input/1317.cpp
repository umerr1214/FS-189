#include <iostream>
#include <string>
#include <stdexcept> // For std::invalid_argument

class MediaItem {
private:
    std::string title;
    int duration; // in minutes/seconds
public:
    // Constructor with input validation and const reference for string to avoid unnecessary copies
    MediaItem(const std::string& t, int d) : title(t), duration(d) {
        if (title.empty()) {
            throw std::invalid_argument("MediaItem title cannot be empty.");
        }
        if (duration <= 0) {
            throw std::invalid_argument("MediaItem duration must be positive.");
        }
    }

    // Getters are const-qualified for good practice and robustness
    std::string getTitle() const { return title; }
    int getDuration() const { return duration; }

    // Virtual destructor for proper polymorphic cleanup, essential for base classes
    virtual ~MediaItem() {
        std::cout << "MediaItem destructor for '" << title << "' called.\n";
    }
};

class Movie : public MediaItem {
private:
    std::string director;
public:
    // Constructor with input validation and const reference for string
    // Uses initializer list for all members (base and derived)
    Movie(const std::string& t, int d, const std::string& dir)
        : MediaItem(t, d), director(dir) 
    {
        if (director.empty()) {
            throw std::invalid_argument("Movie director cannot be empty.");
        }
    }

    // Getter is const-qualified
    std::string getDirector() const { return director; }

    // Override virtual destructor for clarity (optional, but good practice)
    ~Movie() override {
        std::cout << "Movie destructor for '" << getTitle() << "' called.\n";
    }
};

class Song : public MediaItem {
private:
    std::string artist;
public:
    // Constructor with input validation and const reference for string
    // Uses initializer list for all members (base and derived)
    Song(const std::string& t, int d, const std::string& art)
        : MediaItem(t, d), artist(art) 
    {
        if (artist.empty()) {
            throw std::invalid_argument("Song artist cannot be empty.");
        }
    }

    // Getter is const-qualified
    std::string getArtist() const { return artist; }

    // Override virtual destructor for clarity (optional, but good practice)
    ~Song() override {
        std::cout << "Song destructor for '" << getTitle() << "' called.\n";
    }
};

int main() {
    std::cout << "--- Testing MediaItem Hierarchy (Correct Version) ---\n\n";

    // Valid cases
    try {
        Movie movie1("Spirited Away", 125, "Hayao Miyazaki");
        std::cout << "Movie 1 Details:\n";
        std::cout << "  Title: " << movie1.getTitle() << "\n";
        std::cout << "  Duration: " << movie1.getDuration() << " minutes\n";
        std::cout << "  Director: " << movie1.getDirector() << "\n\n";

        Song song1("Imagine", 183, "John Lennon");
        std::cout << "Song 1 Details:\n";
        std::cout << "  Title: " << song1.getTitle() << "\n";
        std::cout << "  Duration: " << song1.getDuration() << " seconds\n";
        std::cout << "  Artist: " << song1.getArtist() << "\n\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating valid items: " << e.what() << "\n\n";
    }

    // Test cases for invalid inputs handled by validation
    std::cout << "--- Testing Invalid Inputs (Validation) ---\n\n";

    try {
        Movie movie2("", 100, "Director Name"); // Attempt to create with empty title
        std::cout << "This line should not be reached for movie2.\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught expected error for movie2: " << e.what() << "\n\n";
    }

    try {
        Song song2("Invalid Song", 0, "Artist Name"); // Attempt to create with non-positive duration
        std::cout << "This line should not be reached for song2.\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught expected error for song2: " << e.what() << "\n\n";
    }

    try {
        Movie movie3("Valid Title", 120, ""); // Attempt to create with empty director
        std::cout << "This line should not be reached for movie3.\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught expected error for movie3: " << e.what() << "\n\n";
    }

    // Demonstrate virtual destructor with polymorphism
    std::cout << "--- Testing Virtual Destructor ---\n\n";
    MediaItem* item1 = new Movie("The Shawshank Redemption", 142, "Frank Darabont");
    MediaItem* item2 = new Song("Hallelujah", 295, "Leonard Cohen");

    std::cout << "Deleting dynamically allocated items...\n";
    delete item1; // Should call Movie destructor, then MediaItem destructor
    delete item2; // Should call Song destructor, then MediaItem destructor
    std::cout << "Dynamically allocated items deleted.\n\n";

    return 0;
}