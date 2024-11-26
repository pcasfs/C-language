#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char word[100];
	int len;
	int cnt = 0;

	scanf("%s", word);
	len = strlen(word);

	for (int i = 0; i < len / 2; i++) {
		if (word[i] == word[len - 1 - i]) {
			cnt++;
		}
	}

	if (cnt == len/2) {
		printf("1");
	}
	else {
		printf("0");
	}
	
}