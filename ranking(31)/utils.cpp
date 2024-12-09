#include <string.h>
#include "utils.h"

void sort_names(char name[][MAX_NAME_LEN], int room[], int room_size) {
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
