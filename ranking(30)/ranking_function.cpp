#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 300
#define MAX_ROOMS 300
#define MAX_NAME_LEN 17

void read_input(int* p, int* m, int level[], char name[][MAX_NAME_LEN]);
int find_room(int level[], int room[MAX_ROOMS][MAX_PLAYERS], int room_size[], int room_count, int player_level, int max_players);
void sort_room_names(char name[][MAX_NAME_LEN], int room[], int room_size);
void print_rooms(int room[MAX_ROOMS][MAX_PLAYERS], int room_size[], int room_count, int level[], char name[][MAX_NAME_LEN]);

int main(void) {
    int p, m;                                    
    int room[MAX_ROOMS][MAX_PLAYERS];           
    int level[MAX_PLAYERS];                     
    char name[MAX_PLAYERS][MAX_NAME_LEN];       
    int room_count = 0;                          
    int room_size[MAX_ROOMS] = { 0 };              

    read_input(&p, &m, level, name);

    for (int i = 0; i < p; i++) {
        int room_index = find_room(level, room, room_size, room_count, level[i], m);
        if (room_index == -1 && room_count < MAX_ROOMS) { 
            room[room_count][0] = i;
            room_size[room_count++] = 1;
        }
        else { 
            room[room_index][room_size[room_index]++] = i;
        }
    }

    print_rooms(room, room_size, room_count, level, name);

    return 0;
}

void read_input(int* p, int* m, int level[], char name[][MAX_NAME_LEN]) {
    scanf("%d %d", p, m);
    for (int i = 0; i < *p; i++) {
        scanf("%d %s", &level[i], name[i]);
    }
}

int find_room(int level[], int room[MAX_ROOMS][MAX_PLAYERS], int room_size[], int room_count, int player_level, int max_players) {
    for (int i = 0; i < room_count; i++) {
        if (room_size[i] < max_players &&
            level[room[i][0]] - 10 <= player_level &&
            player_level <= level[room[i][0]] + 10) {
            return i; 
        }
    }
    return -1; 
}

void sort_room_names(char name[][MAX_NAME_LEN], int room[], int room_size) {
    for (int j = 1; j < room_size; j++) {
        for (int k = j; k > 0; k--) {
            if (strcmp(name[room[k - 1]], name[room[k]]) > 0) {
                int temp = room[k];
                room[k] = room[k - 1];
                room[k - 1] = temp;
            }
        }
    }
}

void print_rooms(int room[MAX_ROOMS][MAX_PLAYERS], int room_size[], int room_count, int level[], char name[][MAX_NAME_LEN]) {
    for (int i = 0; i < room_count; i++) {
        if (room_size[i] == room_size[0]) {
            printf("Started!\n");
        }
        else {
            printf("Waiting!\n");
        }

        sort_room_names(name, room[i], room_size[i]);

        for (int j = 0; j < room_size[i]; j++) {
            printf("%d %s\n", level[room[i][j]], name[room[i][j]]);
        }
    }
}
