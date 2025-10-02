/*List (Doubly Linked List)

Use case: Efficient insertion and deletion in the middle (like managing a playlist).*/

#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> playlist = {"Song1", "Song2", "Song4"};

    // Insert in middle
    auto it = playlist.begin();
    advance(it, 2); // move iterator to 2nd position
    playlist.insert(it, "Song3"); // insert before "Song4"
    // Erase first song
    playlist.erase(playlist.begin());
    // Print playlist
    cout << "Playlist:\n";
    for (auto &song : playlist) cout << song << "\n";
}



