#include <stdio.h>

int main(void) {

	int n, x, y;
	int count = 0;

	int arr[100][100] = { 0 };

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &x, &y);
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				arr[j][k] = 1;
			}
		}
	}

	for (int j = 0; j < 100; j++) {
		for (int k = 0; k < 100; k++) {
			if (arr[j][k] == 1) {
				count++;
			}
		}
	}

	printf("%d", count);

	return 0;

}