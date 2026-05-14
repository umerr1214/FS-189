#include <iostream>
#include <string>
#include <stdexcept> // For potential errors, though the main issue is memory.

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
    Song* _songs;
    int _size;
    int _capacity;

    // Helper to resize array
    void resize(int newCapacity) {
        if (newCapacity <= 0) {
             delete[] _songs;
            _songs = nullptr;
            _capacity = 0;
            _size = 0;
            return;
        }
        Song* newSongs = new Song[newCapacity];
        for (int i = 0; i < _size && i < newCapacity; ++i) {
            newSongs[i] = _songs[i];
        }
        delete[] _songs; // This is crucial for preventing leaks
        _songs = newSongs;
        _capacity = newCapacity;
        if (_size > _capacity) _size = _capacity; // Truncate if new capacity is smaller
    }

public:
    Playlist() : _songs(nullptr), _size(0), _capacity(0) {}

    // Destructor: Frees dynamically allocated memory
    ~Playlist() {
        delete[] _songs;
    }

    // *** ROBUSTNESS ISSUE: Missing user-defined copy constructor and copy assignment operator ***
    // The implicitly generated versions will perform shallow copies of the `_songs` pointer.
    // This leads to multiple Playlist objects pointing to and owning the same dynamically
    // allocated memory. When these objects are destroyed, a double-free error or memory
    // corruption will occur, violating the Rule of Three/Five.

    void addSong(const Song& song) {
        if (_size == _capacity) {
            int newCapacity = (_capacity == 0) ? 1 : _capacity * 2;
            resize(newCapacity);
        }
        _songs[_size++] = song;
    }

    void removeSong(const Song& song) {
        int indexToRemove = -1;
        for (int i = 0; i < _size; ++i) {
            if (_songs[i] == song) {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove != -1) {
            for (int i = indexToRemove; i < _size - 1; ++i) {
                _songs[i] = _songs[i + 1];
            }
            _size--;
            // Not shrinking capacity to keep the issue focused on copy constructor/assignment
        }
    }

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
            // This operation will trigger the robustness issue due to shallow copy.
            // When 'copiedPlaylist' goes out of scope, it will delete the shared
            // '_songs' array. Then, when 'myPlaylist' goes out of scope, it will
            // attempt to delete the same memory again, leading to a double-free.
            Playlist copiedPlaylist = myPlaylist;
            std::cout << "Copied Playlist:\n";
            copiedPlaylist.printPlaylist();
        }
    }

    return 0;
}