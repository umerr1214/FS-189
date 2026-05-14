#include <iostream>
#include <string>
#include <stdexcept>

class Song {
public:
    std::string title;
    std::string artist;

    Song(const std::string& title = "", const std::string& artist = "")
        : title(title), artist(artist) {}

    bool operator==(const Song& other) const {
        return title == other.title && artist == other.artist;
    }
    bool operator!=(const Song& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Song& song) {
        os << "\"" << song.title << "\" by " << song.artist;
        return os;
    }
};

class Playlist {
private:
    Song* _songs;    // Dynamically allocated array of Song objects
    int _size;       // Current number of songs in the playlist
    int _capacity;   // Maximum number of songs the array can hold

    // Helper method to resize the underlying array
    void resize(int newCapacity) {
        if (newCapacity < _size) { // Ensure new capacity can hold existing songs
            newCapacity = _size;
        }
        if (newCapacity == 0) { // Special case for empty playlist
            delete[] _songs;
            _songs = nullptr;
            _capacity = 0;
            _size = 0;
            return;
        }

        Song* newSongs = new Song[newCapacity];
        for (int i = 0; i < _size; ++i) {
            newSongs[i] = _songs[i];
        }
        delete[] _songs;
        _songs = newSongs;
        _capacity = newCapacity;
    }

public:
    // Default constructor
    Playlist() : _songs(nullptr), _size(0), _capacity(0) {}

    // Destructor (Rule of Three/Five)
    ~Playlist() {
        delete[] _songs;
    }

    // Copy Constructor (Rule of Three/Five)
    Playlist(const Playlist& other) : _songs(nullptr), _size(0), _capacity(0) {
        if (other._capacity > 0) {
            _songs = new Song[other._capacity];
            for (int i = 0; i < other._size; ++i) {
                _songs[i] = other._songs[i];
            }
            _size = other._size;
            _capacity = other._capacity;
        }
    }

    // Copy Assignment Operator (Rule of Three/Five)
    Playlist& operator=(const Playlist& other) {
        if (this != &other) { // Self-assignment check
            // Clean up existing resources
            delete[] _songs;

            // Allocate new resources and copy data
            _songs = nullptr; // Initialize to nullptr before potential allocation
            _size = 0;
            _capacity = 0;

            if (other._capacity > 0) {
                _songs = new Song[other._capacity];
                for (int i = 0; i < other._size; ++i) {
                    _songs[i] = other._songs[i];
                }
                _size = other._size;
                _capacity = other._capacity;
            }
        }
        return *this;
    }

    // Move Constructor (optional, but good practice for C++11+)
    Playlist(Playlist&& other) noexcept
        : _songs(other._songs), _size(other._size), _capacity(other._capacity) {
        other._songs = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    // Move Assignment Operator (optional, but good practice for C++11+)
    Playlist& operator=(Playlist&& other) noexcept {
        if (this != &other) {
            delete[] _songs; // Free current resources

            _songs = other._songs;
            _size = other._size;
            _capacity = other._capacity;

            other._songs = nullptr;
            other._size = 0;
            other._capacity = 0;
        }
        return *this;
    }

    // Adds a song to the playlist, resizing if necessary (doubling capacity)
    void addSong(const Song& song) {
        if (_size == _capacity) {
            int newCapacity = (_capacity == 0) ? 1 : _capacity * 2;
            resize(newCapacity);
        }
        _songs[_size++] = song;
    }

    // Removes a song from the playlist
    void removeSong(const Song& song) {
        int indexToRemove = -1;
        for (int i = 0; i < _size; ++i) {
            if (_songs[i] == song) {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove != -1) {
            // Shift elements to the left to fill the gap
            for (int i = indexToRemove; i < _size - 1; ++i) {
                _songs[i] = _songs[i + 1];
            }
            _size--;
            // Optional: Shrink capacity if it's much larger than _size.
            // For simplicity and to avoid frequent reallocations, we won't aggressively shrink here.
            // A common strategy is to shrink if _size is 1/4 of _capacity.
        }
        // If song not found, simply do nothing.
    }

    // Prints all songs in the playlist
    void printPlaylist() const {
        std::cout << "Playlist:\n";
        if (_size == 0) {
            std::cout << "(empty)\n";
            return;
        }
        for (int i = 0; i < _size; ++i) {
            std::cout << _songs[i] << "\n";
        }
    }
};

int main() {
    Playlist myPlaylist;
    std::string command, title, artist;

    while (std::cin >> command) {
        if (command == "add") {
            std::cin.ignore(); // Consume the space after "add"
            std::getline(std::cin, title, ';'); // Read title until ';'
            std::getline(std::cin, artist);     // Read artist until newline
            myPlaylist.addSong(Song(title, artist));
        } else if (command == "remove") {
            std::cin.ignore();
            std::getline(std::cin, title, ';');
            std::getline(std::cin, artist);
            myPlaylist.removeSong(Song(title, artist));
        } else if (command == "print") {
            myPlaylist.printPlaylist();
        } else if (command == "copy_test") {
            Playlist copiedPlaylist = myPlaylist;
            std::cout << "Copied Playlist:\n";
            copiedPlaylist.printPlaylist();
            // Demonstrate that modifying the copy doesn't affect the original
            copiedPlaylist.addSong(Song("New Song", "New Artist"));
            std::cout << "Copied Playlist (modified):\n";
            copiedPlaylist.printPlaylist();
            std::cout << "Original Playlist (after copy and modification of copy):\n";
            myPlaylist.printPlaylist();
        }
    }

    return 0;
}