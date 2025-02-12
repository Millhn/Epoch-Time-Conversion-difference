#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Use Sleep() and adjust if you're on Windows

typedef struct {
    int option;       // Option number
    int duration;     // Duration in minutes
    char description[50]; // Description of the session
} StudySession;

int main(int argc, char *argv[]) {
    int number;

    StudySession sessions[] = {
        {1, 10, "Quick 10-minute focus session"},
        {2, 15, "Moderate 15-minute study time"},
        {3, 25, "Intensive 25-minute Pomodoro session"}
    };

    int session_count = sizeof(sessions) / sizeof(sessions[0]);

    // Declare 'i' outside the loop to comply with older C standards
    int i;

    printf("How long do you want to study?\n");
    for (i = 0; i < session_count; i++) {
        printf("%d. %d minutes - %s\n", sessions[i].option, sessions[i].duration, sessions[i].description);
    }

    printf("Select the number above: ");
    scanf("%d", &number);

    int found = 0;
    for (i = 0; i < session_count; i++) {
        if (sessions[i].option == number) {
            found = 1;
            printf("Starting your study session: %s\n", sessions[i].description);
            printf("You will study for %d minutes.\n", sessions[i].duration);
            
            sleep(sessions[i].duration * 60);  // Convert minutes to seconds
            
            printf("Time's up! Great job completing your session!\n");
            break;
        }
    }

    if (!found) {
        printf("Invalid selection. Please run the program again.\n");
    }

    return 0;
}


