#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int grade;

    scanf("%d", &grade);

    if (grade >= 90 && grade <= 100) {
        printf("A");
    }
    else if (grade >= 80 && grade <= 89) {
        printf("B");
    }
    else if (grade >= 70 && grade <= 79) {
        printf("C");
    }
    else if (grade >= 60 && grade <= 69) {
        printf("D");
    }
    else {
        printf("F");
    }
    return 0;
}
