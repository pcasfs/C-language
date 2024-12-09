#include <stdio.h>
#include "room_manager.h"
#include "utils.h"
#include <string.h>

void assign_to_room(int player_index, int level[], char name[][MAX_NAME_LEN],
    int room[MAX_ROOMS][MAX_PLAYERS], int room_size[], int* room_count, int max_players) {
    for (int i = 0; i < *room_count; i++) {
        if (room_size[i] < max_players &&
            level[room[i][0]] - 10 <= level[player_index] &&
            level[player_index] <= level[room[i][0]] + 10) {
            room[i][room_size[i]++] = player_index;
            return;
        }
    }

    if (*room_count < MAX_ROOMS) {
        room[*room_count][0] = player_index;
        room_size[*room_count] = 1;
        (*room_count)++;
    }
}

void print_rooms(int room[MAX_ROOMS][MAX_PLAYERS], int room_size[], int room_count,
    int level[], char name[][MAX_NAME_LEN], int max_players) {
    for (int i = 0; i < room_count; i++) {
        printf(room_size[i] == max_players ? "Started!\n" : "Waiting!\n");

        sort_names(name, room[i], room_size[i]);

        for (int j = 0; j < room_size[i]; j++) {
            printf("%d %s\n", level[room[i][j]], name[room[i][j]]);
        }
    }
}
