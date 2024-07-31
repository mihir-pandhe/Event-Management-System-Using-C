#include <stdio.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[11];
} Event;

Event events[MAX_EVENTS];
int event_count = 0;

void add_event() {
    if (event_count >= MAX_EVENTS) {
        printf("Event list is full!\n");
        return;
    }
    printf("Enter event name: ");
    scanf(" %[^\n]", events[event_count].name);
    printf("Enter event date (YYYY-MM-DD): ");
    scanf("%s", events[event_count].date);
    event_count++;
}

void view_events() {
    if (event_count == 0) {
        printf("No events to display.\n");
        return;
    }
    for (int i = 0; i < event_count; i++) {
        printf("Event %d: %s on %s\n", i + 1, events[i].name, events[i].date);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nEvent Management System\n");
        printf("1. Add Event\n");
        printf("2. View Events\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_event();
                break;
            case 2:
                view_events();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
