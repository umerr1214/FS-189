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
} // SYNTAX ERROR: Missing semicolon here

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
                for (int j = i; j < count - 1; ++j) {
                    songs[j] = songs[j + 1];
                }
                count--;
                return true;
            }
        }
        return false;
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

    myPlaylist.displayPlaylist();

    std::cout << "\nRemoving \"Song B\"...\n";
    myPlaylist.removeSong("Song B");
    myPlaylist.displayPlaylist();

    std::cout << "\nRemoving \"Non Existent Song\"...\n";
    myPlaylist.removeSong("Non Existent Song");
    myPlaylist.displayPlaylist();

    std::cout << "\nAdding more songs...\n";
    myPlaylist.addSong(Song("Song D", "Artist 4"));
    myPlaylist.addSong(Song("Song E", "Artist 5"));
    myPlaylist.displayPlaylist();

    return 0;
}