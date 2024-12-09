#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H

#define MAX_PLAYERS 300
#define MAX_ROOMS 300
#define MAX_NAME_LEN 17

void assign_to_room(int player_index, int level[], char name[][MAX_NAME_LEN],
    int room[MAX_ROOMS][MAX_PLAYERS], int room_size[], int* room_count, int max_players);
void print_rooms(int room[MAX_ROOMS][MAX_PLAYERS], int room_size[], int room_count,
    int level[], char name[][MAX_NAME_LEN], int max_players);

#endif
