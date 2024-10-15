#include<stdio.h>
#include<stdlib.h>


int main(void) {
    int X, N = 0;
    int result = 0;
    scanf_s("%d", &X);
    scanf_s("%d", &N);

    int* price = (int*)malloc(N * sizeof(int));
    int* ea = (int*)malloc(N * sizeof(int));

    if (price == NULL || ea == NULL) {
        printf("메모리 할당 실패");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf_s("%d %d", &price[i], &ea[i]);
    }
    for (int i = 0; i < N; i++) {
        result += price[i] * ea[i];
    }
    if (result == X) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    free(price);
    free(ea);

    return 0;


}