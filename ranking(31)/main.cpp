#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "room_manager.h"
#include "utils.h"

int main(void) {
    int p, m;                               
    int level[MAX_PLAYERS];                 
    char name[MAX_PLAYERS][MAX_NAME_LEN];   
    int room[MAX_ROOMS][MAX_PLAYERS];       
    int room_size[MAX_ROOMS] = { 0 };       
    int room_count = 0;                     

    scanf("%d %d", &p, &m);
    for (int i = 0; i < p; i++) {
        scanf("%d %s", &level[i], name[i]);
    }

    for (int i = 0; i < p; i++) {
        assign_to_room(i, level, name, room, room_size, &room_count, m);
    }

    print_rooms(room, room_size, room_count, level, name, m);

    return 0;
}
