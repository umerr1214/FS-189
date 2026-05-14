#include <iostream>
#include <string>
#include <utility> // For std::move

class Song {
public:
    std::string title;
    std::string artist;

    Song(std::string t = "", std::string a = "") : title(std::move(t)), artist(std::move(a)) {}

    void display() const {
        std::cout << "\"" << title << "\" by " << artist;
    }
};

class Playlist {
private:
    Song* songs;
    int capacity;
    int count;

    void resize() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Song* newSongs = new Song[newCapacity];
        for (int i = 0; i < count; ++i) {
            newSongs[i] = songs[i];
        }
        delete[] songs;
        songs = newSongs;
        capacity = newCapacity;
    }

public:
    Playlist() : songs(nullptr), capacity(0), count(0) {}
    ~Playlist() {
        delete[] songs;
    }
    Playlist(const Playlist& other) : capacity(other.capacity), count(other.count) {
        songs = new Song[capacity];
        for (int i = 0; i < count; ++i) {
            songs[i] = other.songs[i];
        }
    }
    Playlist& operator=(const Playlist& other) {
        if (this != &other) {
            delete[] songs;
            capacity = other.capacity;
            count = other.count;
            songs = new Song[capacity];
            for (int i = 0; i < count; ++i) {
                songs[i] = other.songs[i];
            }
        }
        return *this;
    }

    void addSong(const Song& song) {
        if (count == capacity) {
            resize();
        }
        songs[count++] = song;
    }

    bool removeSong(const std::string& title) {
        for (int i = 0; i < count; ++i) {
            if (songs[i].title == title) {
                // LOGICAL ERROR: This implementation always removes the *last* song
                // by simply decrementing the count, regardless of which song was found.
                // It does not remove the song specified by 'title' or shift elements.
                if (count > 0) {
                    count--; // This conceptually removes the last song in the array.
                    return true; // Indicates a song was 'removed'
                }
            }
        }
        return false; // Song not found or playlist empty
    }

    void displayPlaylist() const {
        if (count == 0) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        std::cout << "Playlist (" << count << " songs):\n";
        for (int i = 0; i < count; ++i) {
            std::cout << i + 1 << ". ";
            songs[i].display();
            std::cout << "\n";
        }
    }

    int getSongCount() const {
        return count;
    }
};

int main() {
    Playlist myPlaylist;

    myPlaylist.addSong(Song("Song A", "Artist 1"));
    myPlaylist.addSong(Song("Song B", "Artist 2"));
    myPlaylist.addSong(Song("Song C", "Artist 3"));
    myPlaylist.addSong(Song("Song D", "Artist 4"));

    std::cout << "Initial playlist:\n";
    myPlaylist.displayPlaylist();

    std::cout << "\nAttempting to remove \"Song B\"...\n";
    myPlaylist.removeSong("Song B"); // This will find "Song B" but remove "Song D"
    myPlaylist.displayPlaylist();

    std::cout << "\nAttempting to remove \"Song A\"...\n";
    myPlaylist.removeSong("Song A"); // This will find "Song A" but remove "Song C"
    myPlaylist.displayPlaylist();

    std::cout << "\nAttempting to remove \"Non Existent Song\"...\n";
    myPlaylist.removeSong("Non Existent Song"); // Correctly returns false, no change
    myPlaylist.displayPlaylist();

    std::cout << "\nAdding more songs...\n";
    myPlaylist.addSong(Song("Song E", "Artist 5"));
    myPlaylist.displayPlaylist();

    return 0;
}