#include <stdio.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_NAME_LENGTH 100
#define MAX_LOCATION_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 255

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[11];
    char location[MAX_LOCATION_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
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
    printf("Enter event location: ");
    scanf(" %[^\n]", events[event_count].location);
    printf("Enter event description: ");
    scanf(" %[^\n]", events[event_count].description);
    event_count++;
}

void view_events() {
    if (event_count == 0) {
        printf("No events to display.\n");
        return;
    }
    for (int i = 0; i < event_count; i++) {
        printf("\nEvent %d:\n", i + 1);
        printf("Name: %s\n", events[i].name);
        printf("Date: %s\n", events[i].date);
        printf("Location: %s\n", events[i].location);
        printf("Description: %s\n", events[i].description);
    }
}

void search_event() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the event to search for: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < event_count; i++) {
        if (strcmp(events[i].name, name) == 0) {
            printf("\nEvent found:\n");
            printf("Name: %s\n", events[i].name);
            printf("Date: %s\n", events[i].date);
            printf("Location: %s\n", events[i].location);
            printf("Description: %s\n", events[i].description);
            return;
        }
    }
    printf("Event not found.\n");
}

void delete_event() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the event to delete: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < event_count; i++) {
        if (strcmp(events[i].name, name) == 0) {
            for (int j = i; j < event_count - 1; j++) {
                events[j] = events[j + 1];
            }
            event_count--;
            printf("Event deleted.\n");
            return;
        }
    }
    printf("Event not found.\n");
}

void get_user_input(int *choice) {
    while (1) {
        printf("\nEvent Management System\n");
        printf("1. Add Event\n");
        printf("2. View Events\n");
        printf("3. Search Event\n");
        printf("4. Delete Event\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }
}

int main() {
    int choice;
    while (1) {
        get_user_input(&choice);
        switch (choice) {
            case 1:
                add_event();
                break;
            case 2:
                view_events();
                break;
            case 3:
                search_event();
                break;
            case 4:
                delete_event();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
