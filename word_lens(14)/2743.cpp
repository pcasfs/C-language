#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void) {
	char word[101];
	int count = 0;

	scanf("%s", word);
	for (int i = 0; word[i] != '\0'; i++)
		count++;
	printf("%d", count);

	return 0;

}