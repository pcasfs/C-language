#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

    int num[3] = { 0 };
    int max = num[0];
    int i;

    for (i = 0; i < 3; i++) {
        scanf("%d", &num[i]);
    }

    for (i = 0; i < 3; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }

    if (num[0] == num[1] && num[1] == num[2] && num[0] && num[2]) {
        printf("%d", 10000 + (max * 1000));
    }
    else if (num[0] == num[1] || num[1] == num[2]) {
        printf("%d", 1000 + (num[1] * 100));
    }
    else if (num[0] == num[2]) {
        printf("%d", 1000 + (num[0] * 100));
    }
    else {
        printf("%d", 100 * (max));
    }
    return 0;
}