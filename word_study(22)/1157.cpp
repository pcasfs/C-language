#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[1000000];
	int cnt[26] = {0,};	//알파벳의 개수
	int length;
	int max = 0;
	int result = 0;
	int select = 0;
	
	scanf("%s", arr);

	length = strlen(arr);

	for (int i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j < length; j++) {
			if (i == arr[j])
				cnt[i - 'a']++;
		}
	}

	for (int i = 'A'; i <= 'Z'; i++) {
		for (int j = 0; j < length; j++) {
			if (i == arr[j])
				cnt[i - 'A']++;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			select = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max == cnt[i]) {
			result++;
		}
	}

	if (result > 1) {
		printf("?\n");
	}
	else {
		printf("%c", select + 'A'); //%c , select + 'A' 주의
	}

	return 0;
}