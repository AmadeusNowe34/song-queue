#include <stdio.h>
#include "playlist.h"

int main() {
    Song* head = NULL;
    Song* tail = NULL;


    // change songs 
    Song library[10] = {
        {"Out There", "Neito Han", 257},
        {"", "", },
        {"", "", },
        {"", "", },
        {"", "", },
        {"", "", },
        {"", "", },
        {"", "", },
        {"", "", },
        {"", "", }
    };

    printf("*** MUSIC PLAYLIST (C - LINKED LIST QUEUE) ***\n\n");
    
    printf("--- Initial Song Library ---\n");
    for(int i = 0; i < 10; i++) {
        printf("[%d] %s (%s) - %d sec\n", i + 1, library[i].title, library[i].artist, library[i].duration);
    }
    printf("-----------------------------\n");

    int choice, songNum;

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

        if (choice == 1) {
            printf("Enter song number to add (1-10): ");
            scanf("%d", &songNum);
            
            if (songNum >= 1 && songNum <= 10) {
                addSong(&head, &tail, library, songNum - 1);
            } else {
                printf("ERROR: Invalid song number! Please choose 1-10.\n");
            }
        } 
        else if (choice == 2) {
            viewPlaylist(head);
        } 
        else if (choice == 3) {
            playNext(&head, &tail);
        } 
        else if (choice == 4) {
            showTotalDuration(head);
        } 
        else if (choice == 5) {
            printf("Exiting Playlist Program. Goodbye!\n");
            break; 
        } 
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}