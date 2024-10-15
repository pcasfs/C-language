#include <stdio.h>
int main(void)
{
    int A, B, C;
    int one, two, tree, four;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);

    one = (A + B) % C;
    two = ((A % C) + (B % C)) % C;
    tree = (A * B) % C;
    four = ((A % C) * (B % C)) % C;
    printf("%d\n%d\n%d\n%d\n", one, two, tree, four);

    return 0;
}