#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {

	int p, m;				//�÷��̾� ���� ���� �ִ� �ο� ��
	int room[300][300];		//�� �濡 �� �÷��̾���� �ε����� ����(�ִ� 300���� ��� 300���� �÷��̾�)
	int level[300];			//�� �÷��̾��� ���� ����
	char name[300][17];		//�� �÷��̾��� �г��� ����(�ִ� 16���� + NULL)
	int room_count = 0;		//������� ������ ���� ����
	int room_size[300] = { 0 };	//�� �濡 �� �÷��̾� ���� ����		

	scanf("%d %d", &p, &m);
	for (int i = 0; i < p; i++) {
		scanf("%d %s", &level[i], name[i], 17);
	}

	for (int i = 0; i < p; i++) {
		int placed = 0;
		for (int j = 0; j < room_count; j++) {
			if (room_size[j] < m && level[room[j][0]] - 10 <= level[i] && level[i] <= level[room[j][0]] + 10) {
				room[j][room_size[j]++] = i;
				placed = 1;
				break;
			}
		}
		if (!placed && room_count < 300) {
			room[room_count][0] = i;	// ���ο� ���� �����ϰ� �÷��̾� �߰�
			room_size[room_count++] = 1;	// �� ���� ����
			// room_count++�� ���� ���� �������̹Ƿ� 
			// ���� ���� ���� ����� �� ���� 1 ������Ų��.
		}
	}

	//���
	for (int i = 0; i < room_count; i++) {
		if (room_size[i] == m) {
			printf("Started!\n");
		}
		else {
			printf("Waiting!\n");
		}

		//�г��� ����(���� ���� ���)
		for (int j = 1; j < room_size[i]; j++) {
			for (int k = j; k > 0; k--) {
				if (strcmp(name[room[i][k - 1]], name[room[i][k]]) > 0) {
					int temp = room[i][k];
					room[i][k] = room[i][k - 1];
					room[i][k - 1] = temp;
				}
			}
		}

		//�÷��̾� ���
		for (int j = 0; j < room_size[i]; j++) {
			printf("%d %s\n", level[room[i][j]], name[room[i][j]]);
		}
	}
	return 0;
}

