#include <stdio.h>
#include "playlist.h"

int main() {
    // I. Setup pointers for our Linked List Queue
    Song* head = NULL;
    Song* tail = NULL;

    // II. Initial Song Library (10 Songs)
    // You can change these to any songs you like!
    Song library[10] = {
        {"Stairway to Heaven", "Led Zeppelin", 482},
        {"Bohemian Rhapsody", "Queen", 355},
        {"Imagine", "John Lennon", 181},
        {"Hey Jude", "The Beatles", 431},
        {"Hotel California", "Eagles", 390},
        {"Smells Like Teen Spirit", "Nirvana", 301},
        {"Thriller", "Michael Jackson", 357},
        {"Like a Rolling Stone", "Bob Dylan", 373},
        {"Purple Haze", "Jimi Hendrix", 171},
        {"Respect", "Aretha Franklin", 147}
    };

    printf("*** MUSIC PLAYLIST (C - LINKED LIST QUEUE) ***\n\n");
    
    // Display the initial library so the user knows the options
    printf("--- Initial Song Library ---\n");
    for(int i = 0; i < 10; i++) {
        printf("[%d] %s (%s) - %d sec\n", i + 1, library[i].title, library[i].artist, library[i].duration);
    }
    printf("-----------------------------\n");

    int choice, songNum;

    // The Main Loop
    while(1) {
        printf("\n** Playlist Menu **\n");
        printf("1. Add Song to Playlist (Enqueue)\n");
        printf("2. View Current Playlist\n");
        printf("3. Play Next Song (Dequeue)\n");
        printf("4. Show Total Duration\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // III. Menu Logic using If-Else instead of Switch
        if (choice == 1) {
            printf("Enter song number to add (1-10): ");
            scanf("%d", &songNum);
            
            if (songNum >= 1 && songNum <= 10) {
                // Call Enqueue function
                addSong(&head, &tail, library, songNum - 1);
            } else {
                printf("ERROR: Invalid song number! Please choose 1-10.\n");
            }
        } 
        else if (choice == 2) {
            // Call Traversal function
            viewPlaylist(head);
        } 
        else if (choice == 3) {
            // Call Dequeue function
            playNext(&head, &tail);
        } 
        else if (choice == 4) {
            // Call Duration calculation
            showTotalDuration(head);
        } 
        else if (choice == 5) {
            printf("Exiting Playlist Program. Goodbye!\n");
            break; // Exit the while loop
        } 
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}