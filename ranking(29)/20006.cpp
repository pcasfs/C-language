#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {

	int p, m;				//플레이어 수와 방의 최대 인원 수
	int room[300][300];		//각 방에 들어간 플레이어들의 인덱스를 저장(최대 300개의 방과 300명의 플레이어)
	int level[300];			//각 플레이어의 레벨 저장
	char name[300][17];		//각 플레이어의 닉네임 저장(최대 16글자 + NULL)
	int room_count = 0;		//현재까지 생성된 방의 개수
	int room_size[300] = { 0 };	//각 방에 들어간 플레이어 수를 저장		

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
			room[room_count][0] = i;	// 새로운 방을 생성하고 플레이어 추가
			room_size[room_count++] = 1;	// 방 개수 증가
			// room_count++는 후위 증가 연산자이므로 
			// 현재 값을 먼저 사용한 후 값을 1 증가시킨다.
		}
	}

	//출력
	for (int i = 0; i < room_count; i++) {
		if (room_size[i] == m) {
			printf("Started!\n");
		}
		else {
			printf("Waiting!\n");
		}

		//닉네임 정렬(삽입 정렬 사용)
		for (int j = 1; j < room_size[i]; j++) {
			for (int k = j; k > 0; k--) {
				if (strcmp(name[room[i][k - 1]], name[room[i][k]]) > 0) {
					int temp = room[i][k];
					room[i][k] = room[i][k - 1];
					room[i][k - 1] = temp;
				}
			}
		}

		//플레이어 출력
		for (int j = 0; j < room_size[i]; j++) {
			printf("%d %s\n", level[room[i][j]], name[room[i][j]]);
		}
	}
	return 0;
}


