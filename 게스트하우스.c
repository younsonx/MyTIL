#include <stdio.h>
#include <string.h>
#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 30
struct hotel {
    int room_number;
    char customer_name[MAX_NAME_LENGTH];
    int occupied;
};
struct hotel rooms[MAX_ROOMS];
void add_room() {
    int room_number;
    char customer_name[MAX_NAME_LENGTH];
    printf("Enter room number: ");
    if (scanf("%d", &room_number) != 1 || room_number < 1 || room_number > MAX_ROOMS) {
        printf("Invalid room number\n");
        return;
    }
    if (rooms[room_number-1].occupied == 1) {
        printf("Room already occupied\n");
        return;
    }
    printf("Enter guest name: ");
    if (fgets(customer_name, MAX_NAME_LENGTH, stdin) == NULL) {
        printf("Error reading guest name\n");
        return;
    }
    customer_name[strcspn(customer_name, "\n")] = '\0';
    rooms[room_number-1].room_number = room_number;
    strncpy(rooms[room_number-1].customer_name, customer_name, MAX_NAME_LENGTH);
    rooms[room_number-1].occupied = 1;
    printf("Room %d added successfully\n", room_number);
}
void display_rooms() {
    printf("Room\tcustomer Name\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].occupied == 1) {
            printf("%d\t%s\n", rooms[i].room_number, rooms[i].customer_name);
        }
    }
}
void search_room() {
    int room_number;
    printf("Enter room number: ");
    if (scanf("%d", &room_number) != 1 || room_number < 1 || room_number > MAX_ROOMS) {
        printf("Invalid room number\n");
        return;
    }
    if (rooms[room_number-1].occupied == 0) {
        printf("Room not occupied\n");
        return;
    }
    printf("Room %d is occupied by %s\n", rooms[room_number-1].room_number, rooms[room_number-1].customer_name);
}
int main() {
    int choice;
    while (1) {
        printf("\n1. Add room\n2. Display rooms\n3. Search room\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            continue;
        }
        switch(choice) {
            case 1:
                add_room();
                break;
            case 2:
                display_rooms();
                break;
            case 3:
                search_room();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
